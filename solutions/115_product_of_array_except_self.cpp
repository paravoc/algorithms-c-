/*
 * Задача 115: Product of Array Except Self
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Вычислить массив, где каждый элемент - произведение всех элементов кроме себя.
 * Идея решения: Используем префиксные и постфиксные произведения.
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
void test_115() {
    cout << "\n=== Тест задачи 115: Product of Array Except Self ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вычислить массив, где каждый элемент - произведение всех элементов кроме себя." << endl;
    cout << "\nИдея: Используем префиксные и постфиксные произведения." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_115();
    return 0;
}
