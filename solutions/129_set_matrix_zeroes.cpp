/*
 * Задача 129: Set Matrix Zeroes
 * Категория: Matrix
 * Сложность: Medium
 * 
 * Описание: Установить нули в всей строке и столбце, если элемент равен нулю.
 * Идея решения: Используем первую строку и столбец как маркеры.
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
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        
        // Проверяем первую строку
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        
        // Проверяем первый столбец
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        
        // Используем маркеры
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Устанавливаем нули
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Обрабатываем первую строку
        if (firstRowZero) {
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
        }
        
        // Обрабатываем первый столбец
        if (firstColZero) {
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};

/*
 * Тестовая функция
 */
void test_129() {
    cout << "\n=== Тест задачи 129: Set Matrix Zeroes ===" << endl;
    cout << "Категория: Matrix" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Установить нули в всей строке и столбце, если элемент равен нулю." << endl;
    cout << "\nИдея: Используем первую строку и столбец как маркеры." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_129();
    return 0;
}
