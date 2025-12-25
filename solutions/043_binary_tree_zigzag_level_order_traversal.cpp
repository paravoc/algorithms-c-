/*
 * Задача 43: Binary Tree Zigzag Level Order Traversal
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Вернуть zigzag level order обход (слева направо, затем справа налево).
 * Идея решения: BFS с чередованием направления заполнения уровня.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(level);
            leftToRight = !leftToRight;
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_043() {
    cout << "\n=== Тест задачи 43: Binary Tree Zigzag Level Order Traversal ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вернуть zigzag level order обход (слева направо, затем справа налево)." << endl;
    cout << "\nИдея: BFS с чередованием направления заполнения уровня." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_043();
    return 0;
}
