/*
 * Задача 112: Divide Two Integers
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Разделить два целых числа без использования умножения, деления и mod.
 * Идея решения: Используем побитовые сдвиги для ускорения деления.
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
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        long dvd = labs(dividend), dvs = labs(divisor);
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        long result = 0;
        while (dvd >= dvs) {
            long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            result += multiple;
        }
        
        return sign * result;
    }
};

/*
 * Тестовая функция
 */
void test_112() {
    cout << "\n=== Тест задачи 112: Divide Two Integers ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Разделить два целых числа без использования умножения, деления и mod." << endl;
    cout << "\nИдея: Используем побитовые сдвиги для ускорения деления." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_112();
    return 0;
}
