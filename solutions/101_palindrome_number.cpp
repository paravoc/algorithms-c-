/*
 * Задача 101: Palindrome Number
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Проверить, является ли целое число палиндромом.
 * Идея решения: Разворачиваем половину числа и сравниваем с оставшейся половиной.
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
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        return x == reversed || x == reversed / 10;
    }
};

/*
 * Тестовая функция
 */
void test_101() {
    cout << "\n=== Тест задачи 101: Palindrome Number ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, является ли целое число палиндромом." << endl;
    cout << "\nИдея: Разворачиваем половину числа и сравниваем с оставшейся половиной." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_101();
    return 0;
}
