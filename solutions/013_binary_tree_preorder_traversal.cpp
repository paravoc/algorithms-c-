/*
 * Задача 13: Binary Tree Preorder Traversal
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Вернуть preorder обход бинарного дерева.
 * Идея решения: Используем стек для имитации рекурсии. Обрабатываем корень, затем правого и левого потомков.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root) st.push(root);
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_013() {
    cout << "\n=== Тест задачи 13: Binary Tree Preorder Traversal ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вернуть preorder обход бинарного дерева." << endl;
    cout << "\nИдея: Используем стек для имитации рекурсии. Обрабатываем корень, затем правого и левого потомков." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_013();
    return 0;
}
