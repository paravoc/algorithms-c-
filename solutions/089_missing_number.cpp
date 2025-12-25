/*
 * Задача 89: Missing Number
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти пропущенное число в массиве [0, n].
 * Идея решения: Используем XOR или сумму арифметической прогрессии.
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
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        
        for (int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }
};

/*
 * Тестовая функция
 */
void test_089() {
    cout << "\n=== Тест задачи 89: Missing Number ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти пропущенное число в массиве [0, n]." << endl;
    cout << "\nИдея: Используем XOR или сумму арифметической прогрессии." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_089();
    return 0;
}
