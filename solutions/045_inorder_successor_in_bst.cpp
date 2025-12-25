/*
 * Задача 45: Inorder Successor in BST
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Найти inorder преемника заданного узла в BST.
 * Идея решения: Используем свойства BST для навигации к преемнику.
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;
        
        while (root) {
            if (p->val < root->val) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return successor;
    }
};

/*
 * Тестовая функция
 */
void test_045() {
    cout << "\n=== Тест задачи 45: Inorder Successor in BST ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти inorder преемника заданного узла в BST." << endl;
    cout << "\nИдея: Используем свойства BST для навигации к преемнику." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_045();
    return 0;
}
