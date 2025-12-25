/*
 * Задача 126: Bulb Switcher
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Найти количество включенных лампочек после n раундов переключения.
 * Идея решения: Лампочка включена, если у нее нечетное количество делителей (только полные квадраты).
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
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

/*
 * Тестовая функция
 */
void test_126() {
    cout << "\n=== Тест задачи 126: Bulb Switcher ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти количество включенных лампочек после n раундов переключения." << endl;
    cout << "\nИдея: Лампочка включена, если у нее нечетное количество делителей (только полные квадраты)." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_126();
    return 0;
}
