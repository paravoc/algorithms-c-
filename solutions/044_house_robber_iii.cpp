/*
 * Задача 44: House Robber III
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Максимизировать сумму ограбления домов, расположенных в виде бинарного дерева.
 * Идея решения: Динамическое программирование на дереве. Для каждого узла считаем два случая: грабим или не грабим.
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
    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
    
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        int rob = node->val + left.second + right.second;
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        
        return {rob, notRob};
    }
};

/*
 * Тестовая функция
 */
void test_044() {
    cout << "\n=== Тест задачи 44: House Robber III ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Максимизировать сумму ограбления домов, расположенных в виде бинарного дерева." << endl;
    cout << "\nИдея: Динамическое программирование на дереве. Для каждого узла считаем два случая: грабим или не грабим." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_044();
    return 0;
}
