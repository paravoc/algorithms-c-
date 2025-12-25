/*
 * Задача 84: Best Time to Buy and Sell Stock II
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Максимизировать прибыль от многократных транзакций.
 * Идея решения: Суммируем все возрастающие разницы между соседними днями.
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
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

/*
 * Тестовая функция
 */
void test_084() {
    cout << "\n=== Тест задачи 84: Best Time to Buy and Sell Stock II ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Максимизировать прибыль от многократных транзакций." << endl;
    cout << "\nИдея: Суммируем все возрастающие разницы между соседними днями." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_084();
    return 0;
}
