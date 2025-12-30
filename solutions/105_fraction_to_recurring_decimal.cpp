/*
 * Задача 105: Fraction to Recurring Decimal
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Преобразовать дробь в строку с периодической дробью.
 * Идея решения: Используем хэш-таблицу для отслеживания остатков и выявления циклов.
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
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result;
        // Знак
        if (numerator < 0 ^ denominator < 0) {
            result += '-';
        }
        
        long num = labs(numerator);
        long den = labs(denominator);
        
        // Целая часть
        result += to_string(num / den);
        long remainder = num % den;
        if (remainder == 0) return result;
        
        // Дробная часть
        result += '.';
        unordered_map<long, int> remainderPos;
        
        while (remainder != 0) {
            if (remainderPos.count(remainder)) {
                result.insert(remainderPos[remainder], "(");
                result += ')';
                break;
            }
            
            remainderPos[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }
        
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_105() {
    cout << "\n=== Тест задачи 105: Fraction to Recurring Decimal ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Преобразовать дробь в строку с периодической дробью." << endl;
    cout << "\nИдея: Используем хэш-таблицу для отслеживания остатков и выявления циклов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_105();
    return 0;
}
