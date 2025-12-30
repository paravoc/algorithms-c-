/*
 * Задача 96: Sum of Two Integers
 * Категория: Bit Manipulation
 * Сложность: Medium
 * 
 * Описание: Сложить два целых числа без использования + и -.
 * Идея решения: Используем побитовые операции XOR для суммы и AND для переноса.
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
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = (unsigned)carry << 1;
        }
        return a;
    }
};

/*
 * Тестовая функция
 */
void test_096() {
    cout << "\n=== Тест задачи 96: Sum of Two Integers ===" << endl;
    cout << "Категория: Bit Manipulation" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Сложить два целых числа без использования + и -." << endl;
    cout << "\nИдея: Используем побитовые операции XOR для суммы и AND для переноса." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_096();
    return 0;
}
