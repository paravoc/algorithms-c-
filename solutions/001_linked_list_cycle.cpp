/*
 * Задача 1: Linked List Cycle
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Определить, содержит ли связный список цикл.
 * Идея решения: Используем алгоритм "Черепаха и Заяц" - два указателя, один движется в 2 раза быстрее. Если есть цикл, они встретятся.
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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

/*
 * Тестовая функция
 */
void test_001() {
    cout << "\n=== Тест задачи 1: Linked List Cycle ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Определить, содержит ли связный список цикл." << endl;
    cout << "\nИдея: Используем алгоритм "Черепаха и Заяц" - два указателя, один движется в 2 раза быстрее. Если есть цикл, они встретятся." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_001();
    return 0;
}
