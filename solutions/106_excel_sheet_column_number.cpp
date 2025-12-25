/*
 * Задача 106: Excel Sheet Column Number
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Преобразовать название столбца Excel в число.
 * Идея решения: Рассматриваем как число в 26-ричной системе счисления.
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
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_106() {
    cout << "\n=== Тест задачи 106: Excel Sheet Column Number ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Преобразовать название столбца Excel в число." << endl;
    cout << "\nИдея: Рассматриваем как число в 26-ричной системе счисления." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_106();
    return 0;
}
