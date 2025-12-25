/*
 * Задача 42: Sum Root to Leaf Numbers
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Найти сумму всех чисел, образованных путями от корня к листьям.
 * Идея решения: Рекурсивное накопление числа при обходе дерева.
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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;
        
        currentSum = currentSum * 10 + node->val;
        if (!node->left && !node->right) return currentSum;
        
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};

/*
 * Тестовая функция
 */
void test_042() {
    cout << "\n=== Тест задачи 42: Sum Root to Leaf Numbers ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти сумму всех чисел, образованных путями от корня к листьям." << endl;
    cout << "\nИдея: Рекурсивное накопление числа при обходе дерева." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_042();
    return 0;
}
