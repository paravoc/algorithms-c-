/*
 * Задача 111: Plus One
 * Категория: Maths (продолжение)
 * Сложность: Medium
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
void test_111() {
    cout << "\n=== Тест задачи 111: Plus One ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Увеличить число, представленное массивом цифр, на 1." << endl;
    cout << "\nИдея: Обрабатываем перенос с конца массива." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_111();
    return 0;
}
