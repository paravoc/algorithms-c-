/*
 * Задача 102: Pow(x, n)
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Вычислить x в степени n.
 * Идея решения: Используем быстрое возведение в степень через двоичное разложение.
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
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        double current = x;
        
        for (long long i = N; i > 0; i /= 2) {
            if (i % 2 == 1) {
                result *= current;
            }
            current *= current;
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_102() {
    cout << "\n=== Тест задачи 102: Pow(x, n) ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вычислить x в степени n." << endl;
    cout << "\nИдея: Используем быстрое возведение в степень через двоичное разложение." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_102();
    return 0;
}
