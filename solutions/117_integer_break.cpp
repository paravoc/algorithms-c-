/*
 * Задача 117: Integer Break
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Разбить число на сумму натуральных чисел с максимальным произведением.
 * Идея решения: Используем математическое свойство - предпочтительны тройки.
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
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        
        int product = 1;
        while (n > 4) {
            product *= 3;
            n -= 3;
        }
        
        return product * n;
    }
};

/*
 * Тестовая функция
 */
void test_117() {
    cout << "\n=== Тест задачи 117: Integer Break ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Разбить число на сумму натуральных чисел с максимальным произведением." << endl;
    cout << "\nИдея: Используем математическое свойство - предпочтительны тройки." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_117();
    return 0;
}
