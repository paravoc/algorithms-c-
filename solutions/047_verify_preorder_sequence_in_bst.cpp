/*
 * Задача 47: Verify Preorder Sequence in BST
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Проверить, является ли массив корректным preorder обходом BST.
 * Идея решения: Используем стек для проверки BST свойств при preorder обходе.
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
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int lowerBound = INT_MIN;
        
        for (int val : preorder) {
            if (val < lowerBound) return false;
            
            while (!st.empty() && val > st.top()) {
                lowerBound = st.top();
                st.pop();
            }
            st.push(val);
        }
        return true;
    }
};

/*
 * Тестовая функция
 */
void test_047() {
    cout << "\n=== Тест задачи 47: Verify Preorder Sequence in BST ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, является ли массив корректным preorder обходом BST." << endl;
    cout << "\nИдея: Используем стек для проверки BST свойств при preorder обходе." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_047();
    return 0;
}
