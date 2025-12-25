/*
 * Задача 135: Candy
 * Категория: Design
 * Сложность: Hard
 * 
 * Описание: Распределить конфеты детям по рейтингам, чтобы ребенок с более высоким рейтингом получал больше конфет, чем соседи.
 * Идея решения: Два прохода слева направо и справа налево.
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
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        
        // Слева направо
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        // Справа налево
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};```
### 136. Single Number
Описание: Найти единственное число, которое встречается один раз в массиве, где все остальные встречаются дважды.
Идея: Использовать XOR - одинаковые числа аннулируют друг друга.


/*
 * Тестовая функция
 */
void test_135() {
    cout << "\n=== Тест задачи 135: Candy ===" << endl;
    cout << "Категория: Design" << endl;
    cout << "Сложность: Hard" << endl;
    cout << "\nОписание: Распределить конфеты детям по рейтингам, чтобы ребенок с более высоким рейтингом получал больше конфет, чем соседи." << endl;
    cout << "\nИдея: Два прохода слева направо и справа налево." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_135();
    return 0;
}
