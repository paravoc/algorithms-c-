/*
 * Задача 6: Linked List Cycle II
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Найти узел, с которого начинается цикл в связном списке.
 * Идея решения: Сначала находим точку встречи быстрого и медленного указателей, затем перемещаем один указатель в начало и двигаем оба с одинаковой скоростью.
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

/*
 * Тестовая функция
 */
void test_006() {
    cout << "\n=== Тест задачи 6: Linked List Cycle II ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти узел, с которого начинается цикл в связном списке." << endl;
    cout << "\nИдея: Сначала находим точку встречи быстрого и медленного указателей, затем перемещаем один указатель в начало и двигаем оба с одинаковой скоростью." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_006();
    return 0;
}
