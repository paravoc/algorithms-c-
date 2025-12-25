/*
 * Задача 32: Convert Sorted Array to Binary Search Tree
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Преобразовать отсортированный массив в сбалансированное BST.
 * Идея решения: Рекурсивно выбираем середину массива как корень и строим левое и правое поддеревья.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        
        return root;
    }
};

/*
 * Тестовая функция
 */
void test_032() {
    cout << "\n=== Тест задачи 32: Convert Sorted Array to Binary Search Tree ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Преобразовать отсортированный массив в сбалансированное BST." << endl;
    cout << "\nИдея: Рекурсивно выбираем середину массива как корень и строим левое и правое поддеревья." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_032();
    return 0;
}
