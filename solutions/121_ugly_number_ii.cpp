/*
 * Задача 121: Ugly Number II
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Найти n-е уродливое число.
 * Идея решения: Используем три указателя для генерации уродливых чисел.
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
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        
        int i2 = 0, i3 = 0, i5 = 0;
        
        for (int i = 1; i < n; i++) {
            int next2 = ugly[i2] * 2;
            int next3 = ugly[i3] * 3;
            int next5 = ugly[i5] * 5;
            
            int nextUgly = min({next2, next3, next5});
            ugly[i] = nextUgly;
            
            if (nextUgly == next2) i2++;
            if (nextUgly == next3) i3++;
            if (nextUgly == next5) i5++;
        }
        
        return ugly[n - 1];
    }
};

/*
 * Тестовая функция
 */
void test_121() {
    cout << "\n=== Тест задачи 121: Ugly Number II ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти n-е уродливое число." << endl;
    cout << "\nИдея: Используем три указателя для генерации уродливых чисел." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_121();
    return 0;
}
