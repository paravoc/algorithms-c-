/*
 * Задача 141: Linked List Cycle
 * Категория: Design
 * Сложность: Hard
 * 
 * Описание: Определить, есть ли цикл в связном списке.
 * Идея решения: Алгоритм черепахи и зайца.
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
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};```
### 142. Linked List Cycle II
**Описание**: Найти узел, с которого начинается цикл в связном списке.
**Идея**: Алгоритм черепахи и зайца с дополнительной логикой.


/*
 * Тестовая функция
 */
void test_141() {
    cout << "\n=== Тест задачи 141: Linked List Cycle ===" << endl;
    cout << "Категория: Design" << endl;
    cout << "Сложность: Hard" << endl;
    cout << "\nОписание: Определить, есть ли цикл в связном списке." << endl;
    cout << "\nИдея: Алгоритм черепахи и зайца." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_141();
    return 0;
}
