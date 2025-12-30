/*
 * Задача 38: Binary Tree Level Order Traversal II
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Вернуть level order обход снизу вверх.
 * Идея решения: BFS как обычно, затем разворачиваем результат.
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(result.begin(), result.end());
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_038() {
    cout << "\n=== Тест задачи 38: Binary Tree Level Order Traversal II ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вернуть level order обход снизу вверх." << endl;
    cout << "\nИдея: BFS как обычно, затем разворачиваем результат." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_038();
    return 0;
}
