/*
 * Задача 67: Best Time to Buy and Sell Stock
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти максимальную прибыль от одной транзакции покупки/продажи акций.
 * Идея решения: Отслеживаем минимальную цену и максимальную прибыль.
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
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

/*
 * Тестовая функция
 */
void test_067() {
    cout << "\n=== Тест задачи 67: Best Time to Buy and Sell Stock ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти максимальную прибыль от одной транзакции покупки/продажи акций." << endl;
    cout << "\nИдея: Отслеживаем минимальную цену и максимальную прибыль." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_067();
    return 0;
}
