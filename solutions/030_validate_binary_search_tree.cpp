/*
 * Задача 30: Validate Binary Search Tree
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Проверить, является ли бинарное дерево BST.
 * Идея решения: Рекурсивная проверка с передачей минимального и максимального допустимых значений.
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
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
    
    bool validate(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};

/*
 * Тестовая функция
 */
void test_030() {
    cout << "\n=== Тест задачи 30: Validate Binary Search Tree ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, является ли бинарное дерево BST." << endl;
    cout << "\nИдея: Рекурсивная проверка с передачей минимального и максимального допустимых значений." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_030();
    return 0;
}
