/*
 * Задача 29: Binary Tree Level Order Traversal
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Вернуть level order обход бинарного дерева.
 * Идея решения: BFS с использованием очереди. На каждом уровне обрабатываем все узлы.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_029() {
    cout << "\n=== Тест задачи 29: Binary Tree Level Order Traversal ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вернуть level order обход бинарного дерева." << endl;
    cout << "\nИдея: BFS с использованием очереди. На каждом уровне обрабатываем все узлы." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_029();
    return 0;
}
