/*
 * Задача 41: Binary Tree Right Side View
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Вернуть значения узлов, видимых с правой стороны бинарного дерева.
 * Идея решения: BFS, берем последний элемент каждого уровня.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (i == size - 1) result.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_041() {
    cout << "\n=== Тест задачи 41: Binary Tree Right Side View ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вернуть значения узлов, видимых с правой стороны бинарного дерева." << endl;
    cout << "\nИдея: BFS, берем последний элемент каждого уровня." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_041();
    return 0;
}
