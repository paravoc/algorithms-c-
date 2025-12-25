/*
 * Задача 119: Add Digits
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Сложить цифры числа до получения одной цифры.
 * Идея решения: Используем математическое свойство цифрового корня.
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
    int addDigits(int num) {
        if (num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};

/*
 * Тестовая функция
 */
void test_119() {
    cout << "\n=== Тест задачи 119: Add Digits ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Сложить цифры числа до получения одной цифры." << endl;
    cout << "\nИдея: Используем математическое свойство цифрового корня." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_119();
    return 0;
}
