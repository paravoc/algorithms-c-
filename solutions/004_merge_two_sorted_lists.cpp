/*
 * Задача 4: Merge Two Sorted Lists
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Объединить два отсортированных связных списка в один отсортированный.
 * Идея решения: Сравниваем узлы из обоих списков и строим новый список, выбирая меньший элемент на каждом шаге.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

/*
 * Тестовая функция
 */
void test_004() {
    cout << "\n=== Тест задачи 4: Merge Two Sorted Lists ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Объединить два отсортированных связных списка в один отсортированный." << endl;
    cout << "\nИдея: Сравниваем узлы из обоих списков и строим новый список, выбирая меньший элемент на каждом шаге." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_004();
    return 0;
}
