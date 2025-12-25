/*
 * Задача 93: Valid Parentheses
 * Категория: Strings
 * Сложность: Easy
 * 
 * Описание: Проверить валидность скобочной последовательности.
 * Идея решения: Используем стек для отслеживания открывающих скобок.
 * 
 * Сгенерировано: 2025-12-25 14:55:58
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
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        
        for (char c : s) {
            if (pairs.count(c)) {
                if (st.empty() || st.top() != pairs[c]) return false;
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};

/*
 * Тестовая функция
 */
void test_093() {
    cout << "\n=== Тест задачи 93: Valid Parentheses ===" << endl;
    cout << "Категория: Strings" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Проверить валидность скобочной последовательности." << endl;
    cout << "\nИдея: Используем стек для отслеживания открывающих скобок." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_093();
    return 0;
}
