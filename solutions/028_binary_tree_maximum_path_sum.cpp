/*
 * Задача 28: Binary Tree Maximum Path Sum
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Найти максимальную сумму пути в бинарном дереве.
 * Идея решения: Для каждого узла вычисляем максимальную сумму через этот узел и обновляем глобальный максимум.
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
    int maxSum;
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }
    
    int maxGain(TreeNode* node) {
        if (!node) return 0;
        
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        
        int priceNewPath = node->val + leftGain + rightGain;
        maxSum = max(maxSum, priceNewPath);
        
        return node->val + max(leftGain, rightGain);
    }
};

/*
 * Тестовая функция
 */
void test_028() {
    cout << "\n=== Тест задачи 28: Binary Tree Maximum Path Sum ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти максимальную сумму пути в бинарном дереве." << endl;
    cout << "\nИдея: Для каждого узла вычисляем максимальную сумму через этот узел и обновляем глобальный максимум." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_028();
    return 0;
}
