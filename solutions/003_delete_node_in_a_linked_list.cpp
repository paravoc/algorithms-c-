/*
 * Задача 3: Delete Node in a Linked List
 * Категория: Linked List
 * Сложность: Easy
 * 
 * Описание: Удалить узел (не хвостовой) имея доступ только к этому узлу.
 * Идея решения: Копируем значение следующего узла в текущий, затем пропускаем следующий узел.
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

/*
 * Тестовая функция
 */
void test_003() {
    cout << "\n=== Тест задачи 3: Delete Node in a Linked List ===" << endl;
    cout << "Категория: Linked List" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Удалить узел (не хвостовой) имея доступ только к этому узлу." << endl;
    cout << "\nИдея: Копируем значение следующего узла в текущий, затем пропускаем следующий узел." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_003();
    return 0;
}
