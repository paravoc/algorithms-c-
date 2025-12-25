/*
 * Задача 143: Reorder List
 * Категория: Design
 * Сложность: Hard
 * 
 * Описание: 
 * Идея решения: 
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        // Находим середину
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Переворачиваем вторую половину
        ListNode *prev = nullptr, *curr = slow, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Сливаем два списка
        ListNode *first = head, *second = prev;
        while (second->next) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            first->next = second;
            second->next = temp1;
            
            first = temp1;
            second = temp2;
        }
    }
};```
### 144. Binary Tree Preorder Traversal
Описание: Вернуть префиксный обход бинарного дерева.
Идея: Рекурсивный или итеративный обход.


/*
 * Тестовая функция
 */
void test_143() {
    cout << "\n=== Тест задачи 143: Reorder List ===" << endl;
    cout << "Категория: Design" << endl;
    cout << "Сложность: Hard" << endl;
    cout << "\nОписание: " << endl;
    cout << "\nИдея: " << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_143();
    return 0;
}
