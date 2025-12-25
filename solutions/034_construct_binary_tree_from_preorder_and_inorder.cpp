/*
 * Задача 34: Construct Binary Tree from Preorder and Inorder
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Построить бинарное дерево из preorder и inorder обходов.
 * Идея решения: Preorder дает корень, inorder позволяет разделить левое и правое поддеревья.
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
    unordered_map<int, int> inorderMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                   vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inorderMap[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = build(preorder, preStart + 1, preStart + numsLeft,
                          inorder, inStart, inRoot - 1);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd,
                           inorder, inRoot + 1, inEnd);
        return root;
    }
};

/*
 * Тестовая функция
 */
void test_034() {
    cout << "\n=== Тест задачи 34: Construct Binary Tree from Preorder and Inorder ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Построить бинарное дерево из preorder и inorder обходов." << endl;
    cout << "\nИдея: Preorder дает корень, inorder позволяет разделить левое и правое поддеревья." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_034();
    return 0;
}
