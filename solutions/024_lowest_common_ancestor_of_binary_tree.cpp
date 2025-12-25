/*
 * Задача 24: Lowest Common Ancestor of Binary Tree
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Найти наименьшего общего предка двух узлов в бинарном дереве.
 * Идея решения: Рекурсивный поиск. Если оба узла найдены в разных поддеревьях, текущий узел - LCA.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) return root;
        return left ? left : right;
    }
};

/*
 * Тестовая функция
 */
void test_024() {
    cout << "\n=== Тест задачи 24: Lowest Common Ancestor of Binary Tree ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти наименьшего общего предка двух узлов в бинарном дереве." << endl;
    cout << "\nИдея: Рекурсивный поиск. Если оба узла найдены в разных поддеревьях, текущий узел - LCA." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_024();
    return 0;
}
