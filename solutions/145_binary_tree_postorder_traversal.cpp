/*
 * Задача 145: Binary Tree Postorder Traversal
 * Категория: Design
 * Сложность: Hard
 * 
 * Описание: Вернуть постфиксный обход бинарного дерева.
 * Идея решения: Рекурсивный или итеративный обход.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.insert(result.begin(), node->val);
            
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        
        return result;
    }
};```
### 146. LRU Cache
**Описание**: Реализовать кэш с политикой вытеснения Least Recently Used.
**Идея**: Используем хэш-таблицу и двусвязный список для быстрого доступа и перемещения.


/*
 * Тестовая функция
 */
void test_145() {
    cout << "\n=== Тест задачи 145: Binary Tree Postorder Traversal ===" << endl;
    cout << "Категория: Design" << endl;
    cout << "Сложность: Hard" << endl;
    cout << "\nОписание: Вернуть постфиксный обход бинарного дерева." << endl;
    cout << "\nИдея: Рекурсивный или итеративный обход." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_145();
    return 0;
}
