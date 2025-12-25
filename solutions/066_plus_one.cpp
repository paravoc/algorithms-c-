/*
 * Задача 66: Plus One
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Увеличить число, представленное массивом цифр, на 1.
 * Идея решения: Обрабатываем перенос с конца массива.
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
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

/*
 * Тестовая функция
 */
void test_066() {
    cout << "\n=== Тест задачи 66: Plus One ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Увеличить число, представленное массивом цифр, на 1." << endl;
    cout << "\nИдея: Обрабатываем перенос с конца массива." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_066();
    return 0;
}
