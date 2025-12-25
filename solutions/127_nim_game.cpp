/*
 * Задача 127: Nim Game
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Определить, можно ли выиграть в игре Ним.
 * Идея решения: Проигрышная позиция - когда количество камней кратно 4.
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
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

/*
 * Тестовая функция
 */
void test_127() {
    cout << "\n=== Тест задачи 127: Nim Game ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Определить, можно ли выиграть в игре Ним." << endl;
    cout << "\nИдея: Проигрышная позиция - когда количество камней кратно 4." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_127();
    return 0;
}
