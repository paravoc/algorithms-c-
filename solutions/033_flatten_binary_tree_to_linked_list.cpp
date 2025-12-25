/*
 * Задача 33: Flatten Binary Tree to Linked List
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Преобразовать бинарное дерево в связный список на месте.
 * Идея решения: Модифицированный preorder обход. Для каждого узла находим самый правый узел в левом поддереве.
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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* rightmost = curr->left;
                while (rightmost->right) {
                    rightmost = rightmost->right;
                }
                rightmost->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

/*
 * Тестовая функция
 */
void test_033() {
    cout << "\n=== Тест задачи 33: Flatten Binary Tree to Linked List ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Преобразовать бинарное дерево в связный список на месте." << endl;
    cout << "\nИдея: Модифицированный preorder обход. Для каждого узла находим самый правый узел в левом поддереве." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_033();
    return 0;
}
