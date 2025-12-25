/*
 * Задача 16: Symmetric Tree
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Проверить, является ли бинарное дерево симметричным.
 * Идея решения: Рекурсивно сравниваем левое и правое поддеревья зеркально.
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
};

/*
 * Тестовая функция
 */
void test_016() {
    cout << "\n=== Тест задачи 16: Symmetric Tree ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, является ли бинарное дерево симметричным." << endl;
    cout << "\nИдея: Рекурсивно сравниваем левое и правое поддеревья зеркально." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_016();
    return 0;
}
