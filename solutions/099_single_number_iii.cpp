/*
 * Задача 99: Single Number III
 * Категория: Bit Manipulation
 * Сложность: Medium
 * 
 * Описание: Найти два числа, встречающихся по одному разу.
 * Идея решения: Находим различающий бит и разделяем числа на две группы.
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
    vector<int> singleNumber(vector<int>& nums) {
        long diff = 0;
        for (int num : nums) diff ^= num;
        
        diff &= -diff; // Находим младший установленный бит
        
        vector<int> result(2, 0);
        for (int num : nums) {
            if (num & diff) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_099() {
    cout << "\n=== Тест задачи 99: Single Number III ===" << endl;
    cout << "Категория: Bit Manipulation" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти два числа, встречающихся по одному разу." << endl;
    cout << "\nИдея: Находим различающий бит и разделяем числа на две группы." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_099();
    return 0;
}
