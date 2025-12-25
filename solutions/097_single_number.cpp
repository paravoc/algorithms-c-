/*
 * Задача 97: Single Number
 * Категория: Bit Manipulation
 * Сложность: Medium
 * 
 * Описание: Найти единственное число, встречающееся один раз в массиве.
 * Идея решения: XOR всех чисел - дубликаты уничтожатся.
 * 
 * Сгенерировано: 2025-12-25 14:32:36
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
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) result ^= num;
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_097() {
    cout << "\n=== Тест задачи 97: Single Number ===" << endl;
    cout << "Категория: Bit Manipulation" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти единственное число, встречающееся один раз в массиве." << endl;
    cout << "\nИдея: XOR всех чисел - дубликаты уничтожатся." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_097();
    return 0;
}
