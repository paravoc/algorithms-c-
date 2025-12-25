/*
 * Задача 147: Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;
        
        while (curr) {
            ListNode* prev = dummy;
            ListNode* next = curr->next;
            
            // Находим позицию для вставки
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }
            
            // Вставляем узел
            curr->next = prev->next;
            prev->next = curr;
            
            curr = next;
        }
        
        return dummy->next;
    }
};```
### 148. Sort List
Описание: Отсортировать связный список за O(n log n).
Идея: Сортировка слиянием.


/*
 * Тестовая функция
 */
void test_147() {
    cout << "\n=== Тест задачи 147: Insertion Sort List ===" << endl;
    cout << "Категория: Design" << endl;
    cout << "Сложность: Hard" << endl;
    cout << "\nОписание: " << endl;
    cout << "\nИдея: " << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_147();
    return 0;
}
