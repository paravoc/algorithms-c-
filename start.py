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
    <title>134 Algorithms - Полная коллекция задач C++</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/styles/vs2015.min.css">
    <style>
        * {{ margin: 0; padding: 0; box-sizing: border-box; }}
        body {{ font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background: #0d1117; color: #c9d1d9; }}
        .container {{ max-width: 1600px; margin: 0 auto; padding: 20px; display: flex; gap: 20px; }}
        
        /* Sidebar */
        .sidebar {{ width: 350px; background: #161b22; border-radius: 10px; padding: 20px; height: calc(100vh - 40px); position: sticky; top: 20px; border: 1px solid #30363d; }}
        .sidebar h1 {{ color: #58a6ff; margin-bottom: 10px; font-size: 24px; }}
        .stats {{ display: grid; grid-template-columns: 1fr 1fr; gap: 10px; margin-bottom: 20px; }}
        .stat {{ background: #0d1117; padding: 10px; border-radius: 6px; text-align: center; border: 1px solid #30363d; }}
        .stat-number {{ font-size: 24px; font-weight: bold; color: #58a6ff; }}
        .stat-label {{ font-size: 12px; color: #8b949e; }}
        
        /* Search */
        .search {{ width: 100%; padding: 12px; background: #0d1117; border: 1px solid #30363d; border-radius: 6px; color: white; margin-bottom: 15px; }}
        
        /* Categories */
        .categories {{ margin-bottom: 20px; }}
        .category {{ background: #0d1117; padding: 8px 12px; margin-bottom: 5px; border-radius: 6px; border-left: 4px solid #58a6ff; font-size: 14px; }}
        .category-count {{ float: right; background: #238636; padding: 2px 8px; border-radius: 10px; font-size: 12px; }}
        
        /* Problem List */
        .problem-list {{ height: 500px; overflow-y: auto; }}
        .problem-item {{ padding: 12px; margin-bottom: 8px; background: #0d1117; border-radius: 6px; border: 1px solid #30363d; cursor: pointer; transition: all 0.2s; }}
        .problem-item:hover {{ background: #1c2128; border-color: #58a6ff; }}
        .problem-item.active {{ background: #1c2128; border-color: #58a6ff; border-left: 4px solid #58a6ff; }}
        .problem-id {{ color: #58a6ff; font-weight: bold; display: inline-block; width: 40px; }}
        .problem-title {{ color: #c9d1d9; }}
        .problem-meta {{ font-size: 12px; color: #8b949e; margin-top: 5px; }}
        .difficulty {{ display: inline-block; padding: 2px 8px; border-radius: 10px; font-size: 11px; margin-left: 10px; }}
        .easy {{ background: #238636; color: white; }}
        .medium {{ background: #9e6a03; color: white; }}
        .hard {{ background: #da3633; color: white; }}
        
        /* Main Content */
        .main-content {{ flex: 1; background: #161b22; border-radius: 10px; padding: 30px; height: calc(100vh - 40px); overflow-y: auto; border: 1px solid #30363d; }}
        .problem-header {{ margin-bottom: 30px; padding-bottom: 20px; border-bottom: 1px solid #30363d; }}
        #problem-title {{ color: #f0f6fc; font-size: 28px; margin-bottom: 10px; }}
        .header-meta {{ color: #8b949e; font-size: 14px; }}
        .info-box {{ background: #0d1117; padding: 20px; border-radius: 8px; margin-bottom: 20px; border: 1px solid #30363d; }}
        .info-box h3 {{ color: #58a6ff; margin-bottom: 10px; }}
        
        /* Code Section */
        .code-section {{ margin-top: 30px; }}
        .code-header {{ display: flex; justify-content: space-between; align-items: center; margin-bottom: 15px; }}
        .btn {{ padding: 10px 20px; background: #238636; color: white; border: none; border-radius: 6px; cursor: pointer; font-weight: bold; }}
        .btn:hover {{ background: #2ea043; }}
        .code-container {{ background: #0d1117; border-radius: 8px; overflow: hidden; border: 1px solid #30363d; }}
        .code-toolbar {{ background: #161b22; padding: 15px; border-bottom: 1px solid #30363d; display: flex; justify-content: space-between; }}
        pre {{ margin: 0; }}
        code {{ font-family: 'Monaco', 'Consolas', monospace; font-size: 14px; }}
        
        /* Scrollbar */
        ::-webkit-scrollbar {{ width: 8px; }}
        ::-webkit-scrollbar-track {{ background: #0d1117; }}
        ::-webkit-scrollbar-thumb {{ background: #30363d; border-radius: 4px; }}
        ::-webkit-scrollbar-thumb:hover {{ background: #58a6ff; }}
        
        /* Responsive */
        @media (max-width: 1200px) {{
            .container {{ flex-direction: column; }}
            .sidebar {{ width: 100%; height: auto; }}
            .main-content {{ height: auto; }}
        }}
    </style>
</head>
<body>
    <div class="container">
        <!-- Sidebar -->
        <div class="sidebar">
            <h1>🧮 134 Algorithms</h1>
            
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
            
            <input type="text" class="search" id="search" placeholder="🔍 Поиск задачи...">
            
            <div class="categories">
                <h3 style="color: #8b949e; margin-bottom: 10px; font-size: 14px;">КАТЕГОРИИ:</h3>
'''
    
    # Добавляем категории
    for category, count in sorted(category_stats.items()):
        html += f'<div class="category">{category} <span class="category-count">{count}</span></div>\n'
    
    html += '''            </div>
            
            <div class="problem-list" id="problem-list">
                <!-- Список задач будет сгенерирован JavaScript -->
            </div>
        </div>
        
        <!-- Main Content -->
        <div class="main-content">
            <div class="problem-header">
                <h1 id="problem-title">Выберите задачу</h1>
                <div class="header-meta">
                    <span id="problem-id">#000</span> • 
                    <span id="problem-category">Категория</span> • 
                    <span id="problem-difficulty" class="difficulty easy">Сложность</span>
                </div>
            </div>
            
            <div class="info-box">
                <h3>📝 Описание задачи</h3>
                <p id="problem-description">Выберите задачу из списка слева для просмотра описания.</p>
            </div>
            
            <div class="info-box">
                <h3>💡 Идея решения</h3>
                <p id="problem-idea">Идея решения появится здесь после выбора задачи.</p>
            </div>
            
            <div class="code-section">
                <div class="code-header">
                    <h2 style="color: #c9d1d9;">👨‍💻 Решение на C++</h2>
                    <button id="copy-code" class="btn">📋 Копировать код</button>
                </div>
                
                <div class="code-container">
                    <div class="code-toolbar">
                        <div id="file-name" style="color: #8b949e; font-family: monospace;">solution.cpp</div>
                        <div style="color: #8b949e;">C++</div>
                    </div>
                    <pre><code id="code" class="language-cpp">// Выберите задачу для просмотра кода</code></pre>
                </div>
            </div>
        </div>
    </div>
    
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/highlight.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/languages/cpp.min.js"></script>
    
    <script>
        // ВСЕ ЗАДАЧИ ВСТРОЕНЫ В СТРАНИЦУ
        const problems = ''' + json.dumps(problems, ensure_ascii=False, indent=2) + ''';
        
        // Инициализация
        document.addEventListener('DOMContentLoaded', function() {
            // Рендерим список задач
            renderProblemList();
            
            // Загружаем первую задачу
            if (problems.length > 0) {
                loadProblem(problems[0]);
                document.querySelector('.problem-item').classList.add('active');
            }
            
            // Поиск
            document.getElementById('search').addEventListener('input', function(e) {
                const term = e.target.value.toLowerCase();
                document.querySelectorAll('.problem-item').forEach(item => {
                    const text = item.textContent.toLowerCase();
                    item.style.display = text.includes(term) ? 'flex' : 'none';
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
        
        // Рендеринг списка задач
        function renderProblemList() {
            const container = document.getElementById('problem-list');
            container.innerHTML = '';
            
            problems.forEach(problem => {
                const div = document.createElement('div');
                div.className = 'problem-item';
                div.style.display = 'flex';
                div.style.alignItems = 'center';
                div.innerHTML = `
                    <div style="flex: 0 0 40px;">
                        <span class="problem-id">${problem.id.toString().padStart(3, '0')}</span>
                    </div>
                    <div style="flex: 1;">
                        <div class="problem-title">${problem.title}</div>
                        <div class="problem-meta">
                            ${problem.category}
                            <span class="difficulty ${problem.difficulty.toLowerCase()}">${problem.difficulty}</span>
                        </div>
                    </div>
                `;
                
                div.addEventListener('click', () => {
                    document.querySelectorAll('.problem-item').forEach(i => i.classList.remove('active'));
                    div.classList.add('active');
                    loadProblem(problem);
                });
                
                container.appendChild(div);
            });
        }
        
        // Загрузка задачи
        function loadProblem(problem) {
            // Обновляем заголовок
            document.getElementById('problem-title').textContent = problem.title;
            document.getElementById('problem-id').textContent = `#${problem.id.toString().padStart(3, '0')}`;
            document.getElementById('problem-category').textContent = problem.category;
            
            // Обновляем сложность
            const diffElement = document.getElementById('problem-difficulty');
            diffElement.textContent = problem.difficulty;
            diffElement.className = 'difficulty ' + problem.difficulty.toLowerCase();
            
            // Обновляем описание и идею
            document.getElementById('problem-description').textContent = problem.description;
            document.getElementById('problem-idea').textContent = problem.idea;
            
            // Обновляем код
            const codeElement = document.getElementById('code');
            codeElement.textContent = problem.code;
            
            // Обновляем имя файла
            document.getElementById('file-name').textContent = problem.filename;
            
            // Подсвечиваем синтаксис
            hljs.highlightElement(codeElement);
            
            // Прокручиваем к началу
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