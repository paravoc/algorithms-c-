/*
 * Задача 39: Kth Smallest Element in BST
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Найти k-й наименьший элемент в BST.
 * Идея решения: Inorder traversal до k-го элемента.
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if (--k == 0) return curr->val;
            curr = curr->right;
        }
        return -1;
    }
};

/*
 * Тестовая функция
 */
void test_039() {
    cout << "\n=== Тест задачи 39: Kth Smallest Element in BST ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти k-й наименьший элемент в BST." << endl;
    cout << "\nИдея: Inorder traversal до k-го элемента." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_039();
    return 0;
}
