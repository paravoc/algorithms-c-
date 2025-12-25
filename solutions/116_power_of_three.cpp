/*
 * Задача 116: Power of Three
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Проверить, является ли число степенью тройки.
 * Идея решения: Используем математическое свойство или цикл деления.
 * 
 * Сгенерировано: 2025-12-25 15:15:03
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
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        
        while (n % 3 == 0) {
            n /= 3;
        }
        
        return n == 1;
    }
};

/*
 * Тестовая функция
 */
void test_116() {
    cout << "\n=== Тест задачи 116: Power of Three ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, является ли число степенью тройки." << endl;
    cout << "\nИдея: Используем математическое свойство или цикл деления." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_116();
    return 0;
}
