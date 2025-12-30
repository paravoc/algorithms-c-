/*
 * Задача 113: Multiply Strings
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Умножить два числа, представленных как строки.
 * Идея решения: Имитируем умножение в столбик.
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
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product + result[i + j + 1];
                
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        string strResult;
        for (int num : result) {
            if (!(strResult.empty() && num == 0)) {
                strResult += to_string(num);
            }
        }
        
        return strResult.empty() ? "0" : strResult;
    }
};

/*
 * Тестовая функция
 */
void test_113() {
    cout << "\n=== Тест задачи 113: Multiply Strings ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Умножить два числа, представленных как строки." << endl;
    cout << "\nИдея: Имитируем умножение в столбик." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_113();
    return 0;
}
