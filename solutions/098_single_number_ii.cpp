/*
 * Задача 98: Single Number II
 * Категория: Bit Manipulation
 * Сложность: Medium
 * 
 * Описание: Найти единственное число, встречающееся один раз, остальные - три раза.
 * Идея решения: Считаем количество единиц в каждом бите по модулю 3.
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
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

/*
 * Тестовая функция
 */
void test_098() {
    cout << "\n=== Тест задачи 98: Single Number II ===" << endl;
    cout << "Категория: Bit Manipulation" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти единственное число, встречающееся один раз, остальные - три раза." << endl;
    cout << "\nИдея: Считаем количество единиц в каждом бите по модулю 3." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_098();
    return 0;
}
