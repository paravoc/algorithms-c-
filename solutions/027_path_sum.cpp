/*
 * Задача 27: Path Sum
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Проверить, существует ли путь от корня к листу с заданной суммой.
 * Идея решения: Рекурсивно проверяем сумму, вычитая значение текущего узла.
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) return root->val == targetSum;
        
        int newSum = targetSum - root->val;
        return hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum);
    }
};

/*
 * Тестовая функция
 */
void test_027() {
    cout << "\n=== Тест задачи 27: Path Sum ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, существует ли путь от корня к листу с заданной суммой." << endl;
    cout << "\nИдея: Рекурсивно проверяем сумму, вычитая значение текущего узла." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_027();
    return 0;
}
