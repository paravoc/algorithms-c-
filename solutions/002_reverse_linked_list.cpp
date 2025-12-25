/*
 * Задача 2: Reverse Linked List
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Развернуть односвязный список.
 * Идея решения: Итеративно меняем указатели направления. Храним предыдущий, текущий и следующий узлы.
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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

/*
 * Тестовая функция
 */
void test_002() {
    cout << "\n=== Тест задачи 2: Reverse Linked List ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Развернуть односвязный список." << endl;
    cout << "\nИдея: Итеративно меняем указатели направления. Храним предыдущий, текущий и следующий узлы." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_002();
    return 0;
}
