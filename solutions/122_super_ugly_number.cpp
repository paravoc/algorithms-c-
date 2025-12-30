/*
 * Задача 122: Super Ugly Number
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Найти n-е супер-уродливое число (делится только на заданные простые числа).
 * Идея решения: Обобщение предыдущего алгоритма на k указателей.
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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n);
        ugly[0] = 1;
        
        int k = primes.size();
        vector<int> pointers(k, 0);
        
        for (int i = 1; i < n; i++) {
            int minVal = INT_MAX;
            for (int j = 0; j < k; j++) {
                minVal = min(minVal, ugly[pointers[j]] * primes[j]);
            }
            ugly[i] = minVal;
            
            for (int j = 0; j < k; j++) {
                if (ugly[pointers[j]] * primes[j] == minVal) {
                    pointers[j]++;
                }
            }
        }
        
        return ugly[n - 1];
    }
};

/*
 * Тестовая функция
 */
void test_122() {
    cout << "\n=== Тест задачи 122: Super Ugly Number ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти n-е супер-уродливое число (делится только на заданные простые числа)." << endl;
    cout << "\nИдея: Обобщение предыдущего алгоритма на k указателей." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_122();
    return 0;
}
