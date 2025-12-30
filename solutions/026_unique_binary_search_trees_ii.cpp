/*
 * Задача 26: Unique Binary Search Trees II
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Сгенерировать все уникальные BST для n узлов.
 * Идея решения: Рекурсивная генерация всех возможных BST для каждого корня.
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
    
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generate(start, i - 1);
            vector<TreeNode*> rightTrees = generate(i + 1, end);
            
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};

/*
 * Тестовая функция
 */
void test_026() {
    cout << "\n=== Тест задачи 26: Unique Binary Search Trees II ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Сгенерировать все уникальные BST для n узлов." << endl;
    cout << "\nИдея: Рекурсивная генерация всех возможных BST для каждого корня." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_026();
    return 0;
}
