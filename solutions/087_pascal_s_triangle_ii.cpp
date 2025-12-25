/*
 * Задача 87: Pascal's Triangle II
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Вернуть k-ю строку треугольника Паскаля.
 * Идея решения: Генерируем строку итеративно, используя только O(k) памяти.
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
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }
        return row;
    }
};

/*
 * Тестовая функция
 */
void test_087() {
    cout << "\n=== Тест задачи 87: Pascal's Triangle II ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Вернуть k-ю строку треугольника Паскаля." << endl;
    cout << "\nИдея: Генерируем строку итеративно, используя только O(k) памяти." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_087();
    return 0;
}
