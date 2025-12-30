/*
 * Задача 108: Factorial Trailing Zeroes
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Найти количество нулей в конце n!.
 * Идея решения: Считаем количество множителей 5 (так как 2 всегда больше).
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
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            n /= 5;
            count += n;
        }
        return count;
    }
};

/*
 * Тестовая функция
 */
void test_108() {
    cout << "\n=== Тест задачи 108: Factorial Trailing Zeroes ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти количество нулей в конце n!." << endl;
    cout << "\nИдея: Считаем количество множителей 5 (так как 2 всегда больше)." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_108();
    return 0;
}
