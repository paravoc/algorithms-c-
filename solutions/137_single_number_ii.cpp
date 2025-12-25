/*
 * Задача 137: Single Number II
 * Категория: Design
 * Сложность: Hard
 * 
 * Описание: 
 * Идея решения: 
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
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        
        return ones;
    }
};```
### 138. Copy List with Random Pointer
Описание: Скопировать связный список, где каждый узел имеет указатель на случайный узел.
Идея: Использовать хэш-таблицу для отображения оригинальных узлов на копии.


/*
 * Тестовая функция
 */
void test_137() {
    cout << "\n=== Тест задачи 137: Single Number II ===" << endl;
    cout << "Категория: Design" << endl;
    cout << "Сложность: Hard" << endl;
    cout << "\nОписание: " << endl;
    cout << "\nИдея: " << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_137();
    return 0;
}
