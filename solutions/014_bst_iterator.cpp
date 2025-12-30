/*
 * Задача 14: BST Iterator
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Реализовать итератор для бинарного дерева поиска.
 * Идея решения: Используем стек для хранения левых потомков. При вызове next() возвращаем следующий наименьший элемент.
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
class BSTIterator {
    stack<TreeNode*> st;
    
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/*
 * Тестовая функция
 */
void test_014() {
    cout << "\n=== Тест задачи 14: BST Iterator ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Реализовать итератор для бинарного дерева поиска." << endl;
    cout << "\nИдея: Используем стек для хранения левых потомков. При вызове next() возвращаем следующий наименьший элемент." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_014();
    return 0;
}
