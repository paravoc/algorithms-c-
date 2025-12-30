/*
 * Задача 8: Remove Linked List Elements
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Удалить все узлы с заданным значением из связного списка.
 * Идея решения: Используем фиктивный узел для обработки случая, когда нужно удалить голову списка.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *curr = &dummy;
        
        while (curr->next) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};

/*
 * Тестовая функция
 */
void test_008() {
    cout << "\n=== Тест задачи 8: Remove Linked List Elements ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Удалить все узлы с заданным значением из связного списка." << endl;
    cout << "\nИдея: Используем фиктивный узел для обработки случая, когда нужно удалить голову списка." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_008();
    return 0;
}
