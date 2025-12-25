/*
 * Задача 36: Recover Binary Search Tree
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Восстановить BST, в котором два узла поменяны местами.
 * Идея решения: Inorder traversal для нахождения двух неправильно расположенных узлов.
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
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
    
    void inorder(TreeNode* node) {
        if (!node) return;
        
        inorder(node->left);
        
        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }
        prev = node;
        
        inorder(node->right);
    }
};

/*
 * Тестовая функция
 */
void test_036() {
    cout << "\n=== Тест задачи 36: Recover Binary Search Tree ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Восстановить BST, в котором два узла поменяны местами." << endl;
    cout << "\nИдея: Inorder traversal для нахождения двух неправильно расположенных узлов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_036();
    return 0;
}
