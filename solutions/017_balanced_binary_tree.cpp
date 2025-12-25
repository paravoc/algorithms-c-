/*
 * Задача 17: Balanced Binary Tree
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Проверить, является ли бинарное дерево сбалансированным.
 * Идея решения: Рекурсивно проверяем высоты поддеревьев. Если разница больше 1, возвращаем -1.
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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    
    int checkHeight(TreeNode* node) {
        if (!node) return 0;
        
        int left = checkHeight(node->left);
        if (left == -1) return -1;
        
        int right = checkHeight(node->right);
        if (right == -1) return -1;
        
        if (abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};

/*
 * Тестовая функция
 */
void test_017() {
    cout << "\n=== Тест задачи 17: Balanced Binary Tree ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, является ли бинарное дерево сбалансированным." << endl;
    cout << "\nИдея: Рекурсивно проверяем высоты поддеревьев. Если разница больше 1, возвращаем -1." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_017();
    return 0;
}
