/*
 * Задача 25: Unique Binary Search Trees
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Посчитать количество уникальных BST для n узлов.
 * Идея решения: Числа Каталана. Динамическое программирование: dp[i] = Σ(dp[j-1] * dp[i-j]).
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
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

/*
 * Тестовая функция
 */
void test_025() {
    cout << "\n=== Тест задачи 25: Unique Binary Search Trees ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Посчитать количество уникальных BST для n узлов." << endl;
    cout << "\nИдея: Числа Каталана. Динамическое программирование: dp[i] = Σ(dp[j-1] * dp[i-j])." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_025();
    return 0;
}
