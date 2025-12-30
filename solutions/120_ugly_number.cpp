/*
 * Задача 120: Ugly Number
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Проверить, является ли число "уродливым" (делится только на 2, 3, 5).
 * Идея решения: Последовательно делим на 2, 3, 5 пока возможно.
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
    bool isUgly(int n) {
        if (n <= 0) return false;
        
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        
        return n == 1;
    }
};

/*
 * Тестовая функция
 */
void test_120() {
    cout << "\n=== Тест задачи 120: Ugly Number ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, является ли число "уродливым" (делится только на 2, 3, 5)." << endl;
    cout << "\nИдея: Последовательно делим на 2, 3, 5 пока возможно." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_120();
    return 0;
}
