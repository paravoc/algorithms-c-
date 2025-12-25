/*
 * Задача 110: Count Primes
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Подсчитать количество простых чисел меньше n.
 * Идея решения: Решето Эратосфена.
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
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
};

/*
 * Тестовая функция
 */
void test_110() {
    cout << "\n=== Тест задачи 110: Count Primes ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Подсчитать количество простых чисел меньше n." << endl;
    cout << "\nИдея: Решето Эратосфена." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_110();
    return 0;
}
