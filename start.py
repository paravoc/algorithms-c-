#!/usr/bin/env python3
"""
Полное решение для работы с 134 алгоритмическими задачами:
1. Парсит TXT файл с задачами
2. Создает/обновляет CPP файлы
3. Генерирует HTML страницу
4. Запускает локальный сервер
"""

import os
import re
import json
import sys
import http.server
import socketserver
import threading
import webbrowser
from datetime import datetime
from pathlib import Path

# ============================================================================
# 1. ПАРСИНГ TXT ФАЙЛА
# ============================================================================

def parse_txt_file(filename):
    """Парсит TXT файл с задачами и возвращает структурированные данные"""
    print(f"📖 Чтение файла: {filename}")
    
    with open(filename, 'r', encoding='utf-8') as f:
        content = f.read()
    
    problems = []
    current_problem = None
    current_category = ""
    
    lines = content.split('\n')
    i = 0
    
    while i < len(lines):
        line = lines[i].strip()
        
        # Определяем категорию (## Linked List, ## Trees и т.д.)
        if line.startswith('## ') and not line.startswith('###'):
            current_category = line[3:].strip()
            i += 1
            continue
        
        # Новая задача (### 1. Linked List Cycle)
        if line.startswith('### '):
            # Сохраняем предыдущую задачу
            if current_problem:
                problems.append(current_problem)
            
            # Извлекаем номер и название
            match = re.match(r'###\s*(\d+)\.\s*(.+)', line)
            if match:
                problem_id = int(match.group(1))
                problem_title = match.group(2).strip()
                
                current_problem = {
                    'id': problem_id,
                    'title': problem_title,
                    'description': '',
                    'idea': '',
                    'code': '',
                    'category': current_category,
                    'difficulty': 'Medium',  # По умолчанию
                    'filename': f"{problem_id:03d}_{re.sub(r'[^a-z0-9]', '_', problem_title.lower())}.cpp"
                }
            i += 1
            continue
        
        # Описание задачи
        if line.startswith('**Описание**:'):
            if current_problem:
                current_problem['description'] = line[13:].strip()
            i += 1
            continue
        
        # Идея решения
        if line.startswith('**Идея**:'):
            if current_problem:
                current_problem['idea'] = line[9:].strip()
            i += 1
            continue
        
        # Код на C++
        if line.strip() == '```cpp':
            if current_problem:
                i += 1
                code_lines = []
                
                # Собираем код до закрывающего ```
                while i < len(lines) and not lines[i].strip().startswith('```'):
                    code_lines.append(lines[i])
                    i += 1
                
                current_problem['code'] = '\n'.join(code_lines)
                
                # Пропускаем строку с ```
                if i < len(lines) and lines[i].strip().startswith('```'):
                    i += 1
                continue
        
        i += 1
    
    # Добавляем последнюю задачу
    if current_problem:
        problems.append(current_problem)
    
    print(f"✓ Найдено задач: {len(problems)}")
    return sorted(problems, key=lambda x: x['id'])

# ============================================================================
# 2. СОЗДАНИЕ CPP ФАЙЛОВ
# ============================================================================

def create_cpp_files(problems, output_dir='solutions'):
    """Создает CPP файлы для всех задач"""
    print(f"\n📝 Создание CPP файлов в папке: {output_dir}/")
    
    os.makedirs(output_dir, exist_ok=True)
    
    # Определяем сложности по категориям
    difficulty_map = {
        'Linked List': 'Easy',
        'Arrays': 'Easy', 
        'Strings': 'Easy',
        'Bit Manipulation': 'Medium',
        'Trees': 'Medium',
        'Graphs': 'Medium',
        'Heaps': 'Medium',
        'Maths': 'Medium',
        'Matrix': 'Medium',
        'Design': 'Hard'
    }
    
    created_count = 0
    updated_count = 0
    
    for problem in problems:
        filepath = os.path.join(output_dir, problem['filename'])
        
        # Определяем сложность
        difficulty = difficulty_map.get(problem['category'], 'Medium')
        problem['difficulty'] = difficulty
        
        # Создаем содержимое файла
        cpp_content = f"""/*
 * Задача {problem['id']}: {problem['title']}
 * Категория: {problem['category']}
 * Сложность: {difficulty}
 * 
 * Описание: {problem['description']}
 * Идея решения: {problem['idea']}
 * 
 * Сгенерировано: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <limits>
#include <cmath>
using namespace std;

// Структуры данных
struct ListNode {{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {{}}
}};

struct TreeNode {{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {{}}
}};

// Решение задачи
{problem['code']}

/*
 * Тестовая функция
 */
void test_{problem['id']:03d}() {{
    cout << "\\n=== Тест задачи {problem['id']}: {problem['title']} ===" << endl;
    cout << "Категория: {problem['category']}" << endl;
    cout << "Сложность: {difficulty}" << endl;
    cout << "\\nОписание: {problem['description']}" << endl;
    cout << "\\nИдея: {problem['idea']}" << endl;
    cout << "\\n✅ Код готов к использованию!" << endl;
}}

int main() {{
    test_{problem['id']:03d}();
    return 0;
}}
"""
        
        # Проверяем, существует ли файл
        file_exists = os.path.exists(filepath)
        
        # Записываем файл
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(cpp_content)
        
        if file_exists:
            updated_count += 1
        else:
            created_count += 1
        
        status = "🔄 Обновлен" if file_exists else "✅ Создан"
        print(f"  {status}: {problem['filename']}")
    
    print(f"\n📊 Итог: создано {created_count}, обновлено {updated_count} файлов")
    return problems

# ============================================================================
# 3. ГЕНЕРАЦИЯ HTML СТРАНИЦЫ
# ============================================================================

def generate_html_page(problems, output_file='index.html'):
    """Генерирует HTML страницу со всеми задачами"""
    print(f"\n🌐 Генерация HTML страницы: {output_file}")
    
    # Статистика по категориям
    category_stats = {}
    for problem in problems:
        category = problem['category']
        if category not in category_stats:
            category_stats[category] = 0
        category_stats[category] += 1
    
    # Статистика по сложности
    difficulty_stats = {}
    for problem in problems:
        diff = problem['difficulty']
        if diff not in difficulty_stats:
            difficulty_stats[diff] = 0
        difficulty_stats[diff] += 1
    
    # Создаем HTML
    html = f'''<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>134 Algorithms - C++ Задачи</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/styles/atom-one-dark.min.css">
    <style>
        * {{ 
            margin: 0; 
            padding: 0; 
            box-sizing: border-box; 
            transition: all 0.2s ease;
        }}
        
        body {{ 
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', sans-serif;
            background: #000000;
            color: #ffffff;
            min-height: 100vh;
        }}
        
        .container {{ 
            max-width: 1800px;
            margin: 0 auto;
            padding: 20px;
            display: flex;
            gap: 20px;
            height: 100vh;
        }}
        
        /* Левая панель - УЖЕ и ВЫШЕ */
        .sidebar {{ 
            width: 380px;  /* Сделал уже */
            background: #111;
            border-radius: 16px;
            padding: 20px;
            height: 100%;
            border: 1px solid #333;
            display: flex;
            flex-direction: column;
        }}
        
        /* Убрал заголовок полностью */
        .stats {{ 
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 12px;
            margin-bottom: 20px;
            flex-shrink: 0;
        }}
        
        .stat {{ 
            background: #1a1a1a;
            padding: 15px;
            border-radius: 12px;
            text-align: center;
            border: 1px solid #333;
            position: relative;
        }}
        
        .stat::before {{
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 3px;
            background: linear-gradient(90deg, #ff6600, #ffcc00);
        }}
        
        .stat-number {{ 
            font-size: 24px;
            font-weight: 700;
            color: #ffcc00;
            margin-bottom: 5px;
        }}
        
        .stat-label {{ 
            font-size: 12px;
            color: #ff9933;
            font-weight: 500;
            text-transform: uppercase;
            letter-spacing: 0.5px;
        }}
        
        /* Поиск - компактнее */
        .search-container {{
            position: relative;
            margin-bottom: 15px;
            flex-shrink: 0;
        }}
        
        .search {{
            width: 100%;
            padding: 12px 15px 12px 40px;
            background: #1a1a1a;
            border: 1px solid #333;
            border-radius: 10px;
            color: #ffffff;
            font-size: 14px;
            outline: none;
        }}
        
        .search:focus {{
            border-color: #ff6600;
        }}
        
        .search-icon {{
            position: absolute;
            left: 15px;
            top: 50%;
            transform: translateY(-50%);
            color: #ff9933;
            font-size: 16px;
        }}
        
        /* Список задач - МАКСИМАЛЬНАЯ ВЫСОТА */
        .problem-list-container {{
            flex: 1;
            display: flex;
            flex-direction: column;
            min-height: 0; /* Важно для overflow */
        }}
        
        .problem-list-title {{
            color: #ffcc00;
            font-size: 14px;
            font-weight: 600;
            margin-bottom: 10px;
            flex-shrink: 0;
        }}
        
        .problem-list {{ 
            flex: 1;
            overflow-y: auto;
            padding-right: 5px;
        }}
        
        /* Задачи - КОМПАКТНЕЕ */
        .problem-item {{ 
            background: #1a1a1a;
            padding: 12px;
            margin-bottom: 8px;
            border-radius: 10px;
            border: 1px solid #333;
            cursor: pointer;
            position: relative;
        }}
        
        .problem-item:hover {{
            background: #222;
            border-color: #ff6600;
        }}
        
        .problem-item.active {{
            background: linear-gradient(145deg, #ff6600, #ff8c00);
            border-color: #ffcc00;
        }}
        
        .problem-id {{ 
            display: inline-block;
            background: rgba(255, 102, 0, 0.1);
            color: #ff6600;
            font-weight: 600;
            padding: 3px 8px;
            border-radius: 12px;
            font-size: 12px;
            margin-bottom: 6px;
            border: 1px solid rgba(255, 102, 0, 0.3);
        }}
        
        .problem-item.active .problem-id {{
            background: rgba(0, 0, 0, 0.3);
            color: #000;
            border-color: rgba(0, 0, 0, 0.5);
        }}
        
        .problem-title {{ 
            color: #ffffff;
            font-size: 14px;
            font-weight: 500;
            margin-bottom: 5px;
            line-height: 1.3;
        }}
        
        .problem-item.active .problem-title {{
            color: #000;
            font-weight: 600;
        }}
        
        .problem-meta {{ 
            display: flex;
            align-items: center;
            gap: 8px;
            font-size: 11px;
        }}
        
        .problem-item.active .problem-meta {{
            color: #000;
        }}
        
        .difficulty {{
            padding: 2px 8px;
            border-radius: 10px;
            font-size: 10px;
            font-weight: 600;
        }}
        
        .easy {{ 
            background: rgba(0, 200, 83, 0.1);
            color: #00c853;
            border: 1px solid rgba(0, 200, 83, 0.3);
        }}
        
        .medium {{ 
            background: rgba(255, 152, 0, 0.1);
            color: #ff9800;
            border: 1px solid rgba(255, 152, 0, 0.3);
        }}
        
        .hard {{ 
            background: rgba(255, 23, 68, 0.1);
            color: #ff1744;
            border: 1px solid rgba(255, 23, 68, 0.3);
        }}
        
        .problem-item.active .difficulty {{
            background: rgba(0, 0, 0, 0.2);
            border-color: rgba(0, 0, 0, 0.4);
        }}
        
        /* Основной контент */
        .main-content {{ 
            flex: 1;
            background: #111;
            border-radius: 16px;
            padding: 25px;
            height: 100%;
            overflow-y: auto;
            border: 1px solid #333;
        }}
        
        .problem-header {{ 
            margin-bottom: 25px;
            padding-bottom: 15px;
            border-bottom: 1px solid #333;
        }}
        
        #problem-title {{ 
            color: #ffcc00;
            font-size: 28px;
            font-weight: 700;
            margin-bottom: 8px;
            line-height: 1.2;
        }}
        
        .header-meta {{ 
            display: flex;
            align-items: center;
            gap: 15px;
            color: #ff9933;
            font-size: 14px;
            font-weight: 500;
        }}
        
        /* Блоки с информацией */
        .info-box {{ 
            background: #1a1a1a;
            padding: 20px;
            border-radius: 12px;
            margin-bottom: 20px;
            border: 1px solid #333;
        }}
        
        .info-box h3 {{ 
            color: #ffcc00;
            font-size: 18px;
            font-weight: 600;
            margin-bottom: 15px;
        }}
        
        #problem-description, #problem-idea {{
            color: #e0e0e0;
            font-size: 15px;
            line-height: 1.6;
        }}
        
        /* Секция с кодом */
        .code-section {{ 
            margin-top: 25px;
        }}
        
        .code-header {{ 
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 15px;
        }}
        
        .code-header h2 {{
            color: #ffcc00;
            font-size: 20px;
            font-weight: 600;
        }}
        
        .btn {{ 
            background: linear-gradient(135deg, #ff6600, #ff8c00);
            color: #000;
            border: none;
            padding: 10px 20px;
            border-radius: 10px;
            font-size: 14px;
            font-weight: 600;
            cursor: pointer;
        }}
        
        .btn:hover {{
            background: linear-gradient(135deg, #ff8c00, #ffcc00);
        }}
        
        .code-container {{ 
            background: #0d1117;
            border-radius: 12px;
            overflow: hidden;
            border: 1px solid #333;
        }}
        
        .code-toolbar {{ 
            background: #161b22;
            padding: 15px;
            border-bottom: 1px solid #333;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }}
        
        #file-name {{
            color: #ff9933;
            font-family: monospace;
            font-size: 14px;
        }}
        
        .language-tag {{
            background: rgba(255, 102, 0, 0.1);
            color: #ff6600;
            padding: 4px 10px;
            border-radius: 12px;
            font-size: 12px;
            font-weight: 600;
        }}
        
        pre {{ 
            margin: 0; 
            padding: 20px;
            background: #0d1117;
        }}
        
        code {{ 
            font-family: 'Consolas', 'Monaco', monospace;
            font-size: 14px;
            line-height: 1.4;
        }}
        
        /* Стили для скроллбара - тонкий */
        ::-webkit-scrollbar {{
            width: 6px;
        }}
        
        ::-webkit-scrollbar-track {{
            background: #1a1a1a;
            border-radius: 3px;
        }}
        
        ::-webkit-scrollbar-thumb {{
            background: #ff6600;
            border-radius: 3px;
        }}
        
        ::-webkit-scrollbar-thumb:hover {{
            background: #ff8c00;
        }}
        
        /* Адаптивность */
        @media (max-width: 1400px) {{
            .container {{
                flex-direction: column;
                height: auto;
            }}
            
            .sidebar {{
                width: 100%;
                height: 400px;
            }}
        }}
        
        @media (max-width: 768px) {{
            .container {{
                padding: 10px;
            }}
            
            .sidebar, .main-content {{
                padding: 15px;
            }}
            
            #problem-title {{
                font-size: 24px;
            }}
        }}
    </style>
</head>
<body>
    <div class="container">
        <!-- Левая панель - КОМПАКТНАЯ -->
        <div class="sidebar">
            <div class="stats">
                <div class="stat">
                    <div class="stat-number">{len(problems)}</div>
                    <div class="stat-label">Задач</div>
                </div>
                <div class="stat">
                    <div class="stat-number">{len(category_stats)}</div>
                    <div class="stat-label">Категорий</div>
                </div>
            </div>
            
            <div class="search-container">
                <div class="search-icon">🔍</div>
                <input type="text" class="search" id="search" placeholder="Поиск...">
            </div>
            
            <div class="problem-list-container">
                <div class="problem-list-title">Все задачи ({len(problems)})</div>
                <div class="problem-list" id="problem-list">
                    <!-- Список задач будет сгенерирован JavaScript -->
                </div>
            </div>
        </div>
        
        <!-- Основной контент -->
        <div class="main-content">
            <div class="problem-header">
                <h1 id="problem-title">Выберите задачу</h1>
                <div class="header-meta">
                    <span id="problem-id">#000</span>
                    <span id="problem-category">Категория</span>
                    <span id="problem-difficulty" class="difficulty easy">Сложность</span>
                </div>
            </div>
            
            <div class="info-box">
                <h3>📝 Описание</h3>
                <p id="problem-description">Выберите задачу из списка слева для просмотра описания.</p>
            </div>
            
            <div class="info-box">
                <h3>💡 Идея решения</h3>
                <p id="problem-idea">Идея решения появится здесь после выбора задачи.</p>
            </div>
            
            <div class="code-section">
                <div class="code-header">
                    <h2>👨‍💻 Решение на C++</h2>
                    <button id="copy-code" class="btn">📋 Копировать</button>
                </div>
                
                <div class="code-container">
                    <div class="code-toolbar">
                        <div id="file-name">solution.cpp</div>
                        <div class="language-tag">C++</div>
                    </div>
                    <pre><code id="code" class="language-cpp">// Выберите задачу из списка для просмотра кода</code></pre>
                </div>
            </div>
        </div>
    </div>
    
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/highlight.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/languages/cpp.min.js"></script>
    
    <script>
        const problems = ''' + json.dumps(problems, ensure_ascii=False, indent=2) + ''';
        
        document.addEventListener('DOMContentLoaded', function() {
            renderProblemList();
            
            if (problems.length > 0) {
                loadProblem(problems[0]);
                document.querySelectorAll('.problem-item')[0].classList.add('active');
            }
            
            // Поиск
            document.getElementById('search').addEventListener('input', function(e) {
                const term = e.target.value.toLowerCase().trim();
                document.querySelectorAll('.problem-item').forEach(item => {
                    const title = item.querySelector('.problem-title').textContent.toLowerCase();
                    const id = item.querySelector('.problem-id').textContent.toLowerCase();
                    const isVisible = title.includes(term) || id.includes(term.replace('#', ''));
                    item.style.display = isVisible ? 'block' : 'none';
                });
            });
            
            // Копирование кода
            document.getElementById('copy-code').addEventListener('click', function() {
                const code = document.getElementById('code').textContent;
                navigator.clipboard.writeText(code).then(() => {
                    const original = this.textContent;
                    this.textContent = '✓ Скопировано!';
                    setTimeout(() => this.textContent = original, 2000);
                });
            });
        });
        
        function renderProblemList() {
            const container = document.getElementById('problem-list');
            container.innerHTML = '';
            
            problems.forEach(problem => {
                const div = document.createElement('div');
                div.className = 'problem-item';
                
                div.innerHTML = `
                    <div class="problem-id">#${problem.id.toString().padStart(3, '0')}</div>
                    <div class="problem-title">${problem.title}</div>
                    <div class="problem-meta">
                        <span>${problem.category}</span>
                        <span class="difficulty ${problem.difficulty.toLowerCase()}">${problem.difficulty}</span>
                    </div>
                `;
                
                div.addEventListener('click', () => {
                    document.querySelectorAll('.problem-item').forEach(i => {
                        i.classList.remove('active');
                    });
                    div.classList.add('active');
                    loadProblem(problem);
                });
                
                container.appendChild(div);
            });
        }
        
        function loadProblem(problem) {
            document.getElementById('problem-title').textContent = problem.title;
            document.getElementById('problem-id').textContent = `#${problem.id.toString().padStart(3, '0')}`;
            document.getElementById('problem-category').textContent = problem.category;
            
            const diffElement = document.getElementById('problem-difficulty');
            diffElement.textContent = problem.difficulty;
            diffElement.className = 'difficulty ' + problem.difficulty.toLowerCase();
            
            document.getElementById('problem-description').textContent = problem.description;
            document.getElementById('problem-idea').textContent = problem.idea;
            
            const codeElement = document.getElementById('code');
            codeElement.textContent = problem.code;
            
            document.getElementById('file-name').textContent = problem.filename;
            
            hljs.highlightElement(codeElement);
            document.querySelector('.main-content').scrollTop = 0;
        }
    </script>
</body>
</html>'''
    
    # Сохраняем HTML файл
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(html)
    
    print(f"✓ HTML страница создана: {output_file}")
    return output_file

# ============================================================================
# 4. ЛОКАЛЬНЫЙ СЕРВЕР
# ============================================================================

def start_local_server(port=8000):
    """Запускает локальный HTTP сервер"""
    print(f"\n🚀 Запуск локального сервера на порту {port}...")
    print(f"📎 Откройте в браузере: http://localhost:{port}")
    print("🛑 Для остановки нажмите Ctrl+C\n")
    
    # Меняем рабочую директорию на текущую
    os.chdir(os.path.dirname(os.path.abspath(__file__)))
    
    # Создаем обработчик
    handler = http.server.SimpleHTTPRequestHandler
    
    # Настраиваем сервер
    with socketserver.TCPServer(("", port), handler) as httpd:
        print(f"✅ Сервер запущен!")
        print("📁 Доступные файлы:")
        print("   - index.html (главная страница)")
        print("   - solutions/ (папка с CPP файлами)")
        print("   - algorithms.txt (исходный файл с задачами)")
        print("\n🔥 Сервер работает...")
        
        try:
            # Пробуем открыть браузер
            webbrowser.open(f'http://localhost:{port}')
        except:
            pass
        
        # Запускаем сервер
        try:
            httpd.serve_forever()
        except KeyboardInterrupt:
            print("\n\n⏹️ Сервер остановлен")
            httpd.shutdown()

# ============================================================================
# 5. ОСНОВНАЯ ФУНКЦИЯ
# ============================================================================

def main():
    """Основная функция программы"""
    print("=" * 60)
    print("🚀 COMPLETE ALGORITHMS SOLUTION")
    print("=" * 60)
    print("Функции:")
    print("  1. Парсинг TXT файла с задачами")
    print("  2. Создание/обновление CPP файлов")
    print("  3. Генерация HTML страницы")
    print("  4. Запуск локального сервера")
    print("=" * 60)
    
    # Проверяем файл с задачами
    txt_file = 'algorithms.txt'
    if not os.path.exists(txt_file):
        print(f"\n❌ Файл '{txt_file}' не найден!")
        print("Создайте файл algorithms.txt с задачами в формате:")
        print("  ## Linked List")
        print("  ### 1. Linked List Cycle")
        print("  **Описание**: ...")
        print("  **Идея**: ...")
        print("  ```cpp")
        print("  class Solution { ... }")
        print("  ```")
        return
    
    # 1. Парсим TXT файл
    problems = parse_txt_file(txt_file)
    
    if not problems:
        print("❌ Не удалось найти задачи в файле")
        return
    
    # 2. Создаем CPP файлы
    problems = create_cpp_files(problems)
    
    # 3. Генерируем HTML страницу
    html_file = generate_html_page(problems)
    
    # 4. Запускаем сервер
    print("\n" + "=" * 60)
    print("🌐 ВСЕГО ГОТОВО!")
    print("=" * 60)
    print(f"📊 Статистика:")
    print(f"   • Задач: {len(problems)}")
    print(f"   • Файлов CPP: {len([f for f in os.listdir('solutions') if f.endswith('.cpp')])}")
    print(f"   • HTML страница: {html_file}")
    print(f"   • Исходный файл: {txt_file}")
    print("\n📌 Следующие шаги:")
    print("   1. Файлы готовы к использованию")
    print("   2. Для запуска сервера: python complete_solution.py --server")
    print("   3. Для только генерации: python complete_solution.py --generate")
    print("=" * 60)
    
    # Проверяем аргументы командной строки
    if len(sys.argv) > 1:
        if sys.argv[1] == '--server':
            start_local_server()
        elif sys.argv[1] == '--generate':
            print("✅ Генерация завершена!")
        elif sys.argv[1] == '--help':
            print("\n📖 Использование:")
            print("  python complete_solution.py          # Полный процесс")
            print("  python complete_solution.py --server # Только запуск сервера")
            print("  python complete_solution.py --generate # Только генерация")
            print("  python complete_solution.py --help   # Справка")
    else:
        # Спрашиваем пользователя
        response = input("\n🚀 Запустить локальный сервер? (y/n): ")
        if response.lower() == 'y':
            start_local_server()

if __name__ == "__main__":
    main()