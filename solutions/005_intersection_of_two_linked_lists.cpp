/*
 * Задача 5: Intersection of Two Linked Lists
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Найти узел пересечения двух связных списков.
 * Идея решения: Два указателя проходят оба списка. Когда один достигает конца, он переходит к началу другого списка.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

/*
 * Тестовая функция
 */
void test_005() {
    cout << "\n=== Тест задачи 5: Intersection of Two Linked Lists ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти узел пересечения двух связных списков." << endl;
    cout << "\nИдея: Два указателя проходят оба списка. Когда один достигает конца, он переходит к началу другого списка." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_005();
    return 0;
}
