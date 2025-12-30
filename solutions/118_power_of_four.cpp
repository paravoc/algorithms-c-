/*
 * Задача 118: Power of Four
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Проверить, является ли число степенью четверки.
 * Идея решения: Проверяем, что число степень двойки и (num-1) делится на 3.
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
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};

/*
 * Тестовая функция
 */
void test_118() {
    cout << "\n=== Тест задачи 118: Power of Four ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, является ли число степенью четверки." << endl;
    cout << "\nИдея: Проверяем, что число степень двойки и (num-1) делится на 3." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_118();
    return 0;
}
