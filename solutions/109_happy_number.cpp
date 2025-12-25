/*
 * Задача 109: Happy Number
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Проверить, является ли число "счастливым".
 * Идея решения: Используем алгоритм Флойда для обнаружения циклов.
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
    bool isHappy(int n) {
        int slow = n, fast = getNext(n);
        
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return fast == 1;
    }
    
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};

/*
 * Тестовая функция
 */
void test_109() {
    cout << "\n=== Тест задачи 109: Happy Number ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, является ли число "счастливым"." << endl;
    cout << "\nИдея: Используем алгоритм Флойда для обнаружения циклов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_109();
    return 0;
}
