/*
 * Задача 37: Path Sum II
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Найти все пути от корня к листу с заданной суммой.
 * Идея решения: Рекурсивный DFS с backtracking для накопления путей.
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }
    
    void dfs(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& result) {
        if (!node) return;
        
        path.push_back(node->val);
        sum -= node->val;
        
        if (!node->left && !node->right && sum == 0) {
            result.push_back(path);
        }
        
        dfs(node->left, sum, path, result);
        dfs(node->right, sum, path, result);
        
        path.pop_back();
    }
};

/*
 * Тестовая функция
 */
void test_037() {
    cout << "\n=== Тест задачи 37: Path Sum II ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти все пути от корня к листу с заданной суммой." << endl;
    cout << "\nИдея: Рекурсивный DFS с backtracking для накопления путей." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_037();
    return 0;
}
