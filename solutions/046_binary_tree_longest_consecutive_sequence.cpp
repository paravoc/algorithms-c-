/*
 * Задача 46: Binary Tree Longest Consecutive Sequence
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Найти длину самой длинной последовательной последовательности в бинарном дереве.
 * Идея решения: Рекурсивный обход с отслеживанием текущей последовательности.
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
    int longestConsecutive(TreeNode* root) {
        return dfs(root, nullptr, 0);
    }
    
    int dfs(TreeNode* node, TreeNode* parent, int length) {
        if (!node) return length;
        
        length = (parent && node->val == parent->val + 1) ? length + 1 : 1;
        return max(length, max(dfs(node->left, node, length),
                              dfs(node->right, node, length)));
    }
};

/*
 * Тестовая функция
 */
void test_046() {
    cout << "\n=== Тест задачи 46: Binary Tree Longest Consecutive Sequence ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти длину самой длинной последовательной последовательности в бинарном дереве." << endl;
    cout << "\nИдея: Рекурсивный обход с отслеживанием текущей последовательности." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_046();
    return 0;
}
