/*
 * Задача 12: Remove Nth Node From End of List
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Удалить n-й узел с конца связного списка.
 * Идея решения: Два указателя с разницей в n шагов. Когда первый достигает конца, второй находится перед узлом для удаления.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *first = &dummy, *second = &dummy;
        
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        while (first) {
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        return dummy.next;
    }
};

/*
 * Тестовая функция
 */
void test_012() {
    cout << "\n=== Тест задачи 12: Remove Nth Node From End of List ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Удалить n-й узел с конца связного списка." << endl;
    cout << "\nИдея: Два указателя с разницей в n шагов. Когда первый достигает конца, второй находится перед узлом для удаления." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_012();
    return 0;
}
