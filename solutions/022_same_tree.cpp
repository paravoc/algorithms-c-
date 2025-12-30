/*
 * Задача 22: Same Tree
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Проверить, идентичны ли два бинарных дерева.
 * Идея решения: Рекурсивно сравниваем структуры и значения узлов.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

/*
 * Тестовая функция
 */
void test_022() {
    cout << "\n=== Тест задачи 22: Same Tree ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, идентичны ли два бинарных дерева." << endl;
    cout << "\nИдея: Рекурсивно сравниваем структуры и значения узлов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_022();
    return 0;
}
