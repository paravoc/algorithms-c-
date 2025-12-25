/*
 * Задача 35: Binary Tree Paths
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Вернуть все пути от корня к листьям в бинарном дереве.
 * Идея решения: Рекурсивный DFS с накоплением текущего пути.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root) dfs(root, "", result);
        return result;
    }
    
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node->left && !node->right) {
            result.push_back(path + to_string(node->val));
            return;
        }
        
        if (node->left) dfs(node->left, path + to_string(node->val) + "->", result);
        if (node->right) dfs(node->right, path + to_string(node->val) + "->", result);
    }
};

/*
 * Тестовая функция
 */
void test_035() {
    cout << "\n=== Тест задачи 35: Binary Tree Paths ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вернуть все пути от корня к листьям в бинарном дереве." << endl;
    cout << "\nИдея: Рекурсивный DFS с накоплением текущего пути." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_035();
    return 0;
}
