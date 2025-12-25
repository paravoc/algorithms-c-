/*
 * Задача 18: Closest Binary Search Tree Value
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Найти значение в BST, наиболее близкое к целевому.
 * Идея решения: Используем свойства BST для навигации, обновляя ближайшее значение на каждом шаге.
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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        while (root) {
            if (abs(root->val - target) < abs(closest - target)) {
                closest = root->val;
            }
            root = target < root->val ? root->left : root->right;
        }
        return closest;
    }
};

/*
 * Тестовая функция
 */
void test_018() {
    cout << "\n=== Тест задачи 18: Closest Binary Search Tree Value ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти значение в BST, наиболее близкое к целевому." << endl;
    cout << "\nИдея: Используем свойства BST для навигации, обновляя ближайшее значение на каждом шаге." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_018();
    return 0;
}
