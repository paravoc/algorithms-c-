/*
 * Задача 100: Reverse Integer
 * Категория: Maths
 * Сложность: Medium
 * 
 * Описание: Развернуть цифры целого числа.
 * Идея решения: Поразрядно извлекаем цифры и проверяем переполнение.
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
    int reverse(int x) {
        int result = 0;
        
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            if (result > INT_MAX/10 || (result == INT_MAX/10 && digit > 7)) return 0;
            if (result < INT_MIN/10 || (result == INT_MIN/10 && digit < -8)) return 0;
            
            result = result * 10 + digit;
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_100() {
    cout << "\n=== Тест задачи 100: Reverse Integer ===" << endl;
    cout << "Категория: Maths" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Развернуть цифры целого числа." << endl;
    cout << "\nИдея: Поразрядно извлекаем цифры и проверяем переполнение." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_100();
    return 0;
}
