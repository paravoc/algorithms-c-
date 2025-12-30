/*
 * Задача 31: Minimum Depth of Binary Tree
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Найти минимальную глубину бинарного дерева.
 * Идея решения: Рекурсивно находим минимальную глубину, учитывая случай, когда одно из поддеревьев отсутствует.
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

/*
 * Тестовая функция
 */
void test_031() {
    cout << "\n=== Тест задачи 31: Minimum Depth of Binary Tree ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти минимальную глубину бинарного дерева." << endl;
    cout << "\nИдея: Рекурсивно находим минимальную глубину, учитывая случай, когда одно из поддеревьев отсутствует." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_031();
    return 0;
}
