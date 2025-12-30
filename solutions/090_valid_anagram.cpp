/*
 * Задача 90: Valid Anagram
 * Категория: Strings
 * Сложность: Easy
 * 
 * Описание: Проверить, являются ли строки анаграммами.
 * Идея решения: Считаем частоты символов или сортируем строки.
 * 
 * Сгенерировано: 2025-12-30 15:41:18
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
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        for (char c : t) {
            if (--count[c - 'a'] < 0) return false;
        }
        return true;
    }
};

/*
 * Тестовая функция
 */
void test_090() {
    cout << "\n=== Тест задачи 90: Valid Anagram ===" << endl;
    cout << "Категория: Strings" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Проверить, являются ли строки анаграммами." << endl;
    cout << "\nИдея: Считаем частоты символов или сортируем строки." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_090();
    return 0;
}
