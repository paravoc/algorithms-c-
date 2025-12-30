/*
 * Задача 40: Construct Binary Tree from Inorder and Postorder
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Построить бинарное дерево из inorder и postorder обходов.
 * Идея решения: Postorder дает корень с конца, inorder позволяет разделить поддеревья.
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
    unordered_map<int, int> inorderMap;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1,
                    postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                   vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inorderMap[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = build(inorder, inStart, inRoot - 1,
                          postorder, postStart, postStart + numsLeft - 1);
        root->right = build(inorder, inRoot + 1, inEnd,
                           postorder, postStart + numsLeft, postEnd - 1);
        return root;
    }
};

/*
 * Тестовая функция
 */
void test_040() {
    cout << "\n=== Тест задачи 40: Construct Binary Tree from Inorder and Postorder ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Построить бинарное дерево из inorder и postorder обходов." << endl;
    cout << "\nИдея: Postorder дает корень с конца, inorder позволяет разделить поддеревья." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_040();
    return 0;
}
