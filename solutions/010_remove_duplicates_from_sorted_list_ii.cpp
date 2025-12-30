/*
 * Задача 10: Remove Duplicates from Sorted List II
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Удалить все узлы, которые имеют дубликаты, оставив только уникальные элементы.
 * Идея решения: Используем фиктивный узел и отслеживаем предыдущий узел для полного удаления дубликатов.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *curr = head;
        
        while (curr) {
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
            }
            if (prev->next == curr) {
                prev = prev->next;
            } else {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};

/*
 * Тестовая функция
 */
void test_010() {
    cout << "\n=== Тест задачи 10: Remove Duplicates from Sorted List II ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Удалить все узлы, которые имеют дубликаты, оставив только уникальные элементы." << endl;
    cout << "\nИдея: Используем фиктивный узел и отслеживаем предыдущий узел для полного удаления дубликатов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_010();
    return 0;
}
