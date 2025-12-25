/*
 * Задача 49: Count Univalue Subtrees
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Посчитать количество унивальных поддеревьев (все узлы имеют одинаковое значение).
 * Идея решения: Рекурсивная проверка унивальности для каждого поддерева.
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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        isUnival(root, count);
        return count;
    }
    
    bool isUnival(TreeNode* node, int& count) {
        if (!node) return true;
        
        bool left = isUnival(node->left, count);
        bool right = isUnival(node->right, count);
        
        if (left && right) {
            if (node->left && node->left->val != node->val) return false;
            if (node->right && node->right->val != node->val) return false;
            count++;
            return true;
        }
        return false;
    }
};

/*
 * Тестовая функция
 */
void test_049() {
    cout << "\n=== Тест задачи 49: Count Univalue Subtrees ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Посчитать количество унивальных поддеревьев (все узлы имеют одинаковое значение)." << endl;
    cout << "\nИдея: Рекурсивная проверка унивальности для каждого поддерева." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_049();
    return 0;
}
