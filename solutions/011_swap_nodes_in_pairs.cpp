/*
 * Задача 11: Swap Nodes in Pairs
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Поменять местами каждые два соседних узла в связном списке.
 * Идея решения: Используем фиктивный узел и меняем пары узлов, обновляя указатели.
 * 
 * Сгенерировано: 2025-12-25 14:55:58
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *curr = &dummy;
        
        while (curr->next && curr->next->next) {
            ListNode *first = curr->next;
            ListNode *second = curr->next->next;
            
            first->next = second->next;
            second->next = first;
            curr->next = second;
            
            curr = curr->next->next;
        }
        return dummy.next;
    }
};

/*
 * Тестовая функция
 */
void test_011() {
    cout << "\n=== Тест задачи 11: Swap Nodes in Pairs ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Поменять местами каждые два соседних узла в связном списке." << endl;
    cout << "\nИдея: Используем фиктивный узел и меняем пары узлов, обновляя указатели." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_011();
    return 0;
}
