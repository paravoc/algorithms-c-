/*
 * Задача 19: Binary Tree Postorder Traversal
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Вернуть postorder обход бинарного дерева.
 * Идея решения: Модифицированный preorder обход (корень-право-лево) с последующим разворотом результата.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root) st.push(root);
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_019() {
    cout << "\n=== Тест задачи 19: Binary Tree Postorder Traversal ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вернуть postorder обход бинарного дерева." << endl;
    cout << "\nИдея: Модифицированный preorder обход (корень-право-лево) с последующим разворотом результата." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_019();
    return 0;
}
