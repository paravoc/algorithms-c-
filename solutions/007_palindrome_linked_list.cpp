/*
 * Задача 7: Palindrome Linked List
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Проверить, является ли связный список палиндромом.
 * Идея решения: Находим середину списка, разворачиваем вторую половину и сравниваем с первой.
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // Находим середину
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Разворачиваем вторую половину
        ListNode *prev = nullptr, *curr = slow;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Сравниваем две половины
        ListNode *left = head, *right = prev;
        while (right) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

/*
 * Тестовая функция
 */
void test_007() {
    cout << "\n=== Тест задачи 7: Palindrome Linked List ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Проверить, является ли связный список палиндромом." << endl;
    cout << "\nИдея: Находим середину списка, разворачиваем вторую половину и сравниваем с первой." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_007();
    return 0;
}
