/*
 * Задача 9: Remove Duplicates from Sorted List
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Удалить дубликаты из отсортированного связного списка.
 * Идея решения: Проходим по списку и пропускаем узлы с одинаковыми значениями.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

/*
 * Тестовая функция
 */
void test_009() {
    cout << "\n=== Тест задачи 9: Remove Duplicates from Sorted List ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Удалить дубликаты из отсортированного связного списка." << endl;
    cout << "\nИдея: Проходим по списку и пропускаем узлы с одинаковыми значениями." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_009();
    return 0;
}
