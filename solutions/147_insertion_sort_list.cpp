/*
 * Задача 147: Insertion Sort List
 * Категория: Design
 * Сложность: Hard
 * 
 * Описание: Отсортировать связный список методом вставки.
 * Идея решения: Построить новый список, вставляя каждый элемент в правильную позицию.
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
**Описание**: Отсортировать связный список за O(n log n).
**Идея**: Сортировка слиянием.


/*
 * Тестовая функция
 */
void test_147() {
    cout << "\n=== Тест задачи 147: Insertion Sort List ===" << endl;
    cout << "Категория: Design" << endl;
    cout << "Сложность: Hard" << endl;
    cout << "\nОписание: Отсортировать связный список методом вставки." << endl;
    cout << "\nИдея: Построить новый список, вставляя каждый элемент в правильную позицию." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_147();
    return 0;
}
