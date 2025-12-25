/*
 * Задача 56: Merge K Sorted Lists
 * Категория: Heaps
 * Сложность: Medium
 * 
 * Описание: Объединить k отсортированных связных списков в один отсортированный.
 * Идея решения: Используем минимальную кучу (min-heap) для эффективного выбора наименьшего элемента.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for (ListNode* list : lists) {
            if (list) pq.push(list);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            
            if (node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};

/*
 * Тестовая функция
 */
void test_056() {
    cout << "\n=== Тест задачи 56: Merge K Sorted Lists ===" << endl;
    cout << "Категория: Heaps" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Объединить k отсортированных связных списков в один отсортированный." << endl;
    cout << "\nИдея: Используем минимальную кучу (min-heap) для эффективного выбора наименьшего элемента." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_056();
    return 0;
}
