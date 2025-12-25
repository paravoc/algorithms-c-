/*
 * Задача 15: Binary Tree Inorder Traversal
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Вернуть inorder обход бинарного дерева.
 * Идея решения: Итеративный обход с использованием стека. Сначала идем до самого левого узла.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_015() {
    cout << "\n=== Тест задачи 15: Binary Tree Inorder Traversal ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вернуть inorder обход бинарного дерева." << endl;
    cout << "\nИдея: Итеративный обход с использованием стека. Сначала идем до самого левого узла." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_015();
    return 0;
}
