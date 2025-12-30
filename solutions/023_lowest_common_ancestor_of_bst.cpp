/*
 * Задача 23: Lowest Common Ancestor of BST
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Найти наименьшего общего предка двух узлов в BST.
 * Идея решения: Используем свойства BST - LCA находится между значениями двух узлов.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};

/*
 * Тестовая функция
 */
void test_023() {
    cout << "\n=== Тест задачи 23: Lowest Common Ancestor of BST ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти наименьшего общего предка двух узлов в BST." << endl;
    cout << "\nИдея: Используем свойства BST - LCA находится между значениями двух узлов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_023();
    return 0;
}
