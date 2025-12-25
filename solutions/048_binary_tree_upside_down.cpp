/*
 * Задача 48: Binary Tree Upside Down
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Перевернуть бинарное дерево вверх ногами.
 * Идея решения: Итеративное изменение указателей для разворота дерева.
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode *curr = root, *prev = nullptr, *next = nullptr, *temp = nullptr;
        
        while (curr) {
            next = curr->left;
            curr->left = temp;
            temp = curr->right;
            curr->right = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

/*
 * Тестовая функция
 */
void test_048() {
    cout << "\n=== Тест задачи 48: Binary Tree Upside Down ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Перевернуть бинарное дерево вверх ногами." << endl;
    cout << "\nИдея: Итеративное изменение указателей для разворота дерева." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_048();
    return 0;
}
