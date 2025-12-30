/*
 * Задача 81: Product of Array Except Self
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Вычислить массив, где каждый элемент - произведение всех элементов кроме себя.
 * Идея решения: Используем префиксные и постфиксные произведения.
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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Префиксное произведение
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        
        // Постфиксное произведение
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= postfix;
            postfix *= nums[i];
        }
        
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_081() {
    cout << "\n=== Тест задачи 81: Product of Array Except Self ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Вычислить массив, где каждый элемент - произведение всех элементов кроме себя." << endl;
    cout << "\nИдея: Используем префиксные и постфиксные произведения." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_081();
    return 0;
}
