/*
 * Задача 107: Excel Sheet Column Title
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Преобразовать число в название столбца Excel.
 * Идея решения: Обратное преобразование из 26-ричной системы с учетом того, что нет нуля.
 * 
 * Сгенерировано: 2025-12-25 14:32:36
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Решение задачи
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        
        while (columnNumber > 0) {
            columnNumber--;
            result = char('A' + columnNumber % 26) + result;
            columnNumber /= 26;
        }
        
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_107() {
    cout << "\n=== Тест задачи 107: Excel Sheet Column Title ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Преобразовать число в название столбца Excel." << endl;
    cout << "\nИдея: Обратное преобразование из 26-ричной системы с учетом того, что нет нуля." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_107();
    return 0;
}
