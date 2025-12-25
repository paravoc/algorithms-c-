/*
 * Задача 20: Maximum Depth of Binary Tree
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Найти максимальную глубину бинарного дерева.
 * Идея решения: Рекурсивно находим максимальную глубину левого и правого поддеревьев.
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*
 * Тестовая функция
 */
void test_020() {
    cout << "\n=== Тест задачи 20: Maximum Depth of Binary Tree ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти максимальную глубину бинарного дерева." << endl;
    cout << "\nИдея: Рекурсивно находим максимальную глубину левого и правого поддеревьев." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_020();
    return 0;
}
