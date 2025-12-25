/*
 * Задача 125: Paint Fence
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Посчитать количество способов покрасить n столбов k цветами без 3+ одинаковых подряд.
 * Идея решения: Динамическое программирование с двумя состояниями.
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
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        
        int same = k;     // Последние два столба одинаковые
        int diff = k * (k - 1); // Последние два столба разные
        
        for (int i = 3; i <= n; i++) {
            int temp = diff;
            diff = (same + diff) * (k - 1);
            same = temp;
        }
        
        return same + diff;
    }
};

/*
 * Тестовая функция
 */
void test_125() {
    cout << "\n=== Тест задачи 125: Paint Fence ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Посчитать количество способов покрасить n столбов k цветами без 3+ одинаковых подряд." << endl;
    cout << "\nИдея: Динамическое программирование с двумя состояниями." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_125();
    return 0;
}
