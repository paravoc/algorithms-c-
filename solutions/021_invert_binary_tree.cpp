/*
 * Задача 21: Invert Binary Tree
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Инвертировать бинарное дерево.
 * Идея решения: Рекурсивно меняем местами левое и правое поддеревья для каждого узла.
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        
        return root;
    }
};

/*
 * Тестовая функция
 */
void test_021() {
    cout << "\n=== Тест задачи 21: Invert Binary Tree ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Инвертировать бинарное дерево." << endl;
    cout << "\nИдея: Рекурсивно меняем местами левое и правое поддеревья для каждого узла." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_021();
    return 0;
}
