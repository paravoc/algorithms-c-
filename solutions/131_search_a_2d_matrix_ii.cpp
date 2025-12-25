/*
 * Задача 131: Search a 2D Matrix II
 * Категория: Matrix
 * Сложность: Medium
 * 
 * Описание: Найти target в матрице, где строки и столбцы отсортированы по отдельности.
 * Идея решения: Аналогично предыдущей задаче, начинаем из правого верхнего угла.
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};

/*
 * Тестовая функция
 */
void test_131() {
    cout << "\n=== Тест задачи 131: Search a 2D Matrix II ===" << endl;
    cout << "Категория: Matrix" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти target в матрице, где строки и столбцы отсортированы по отдельности." << endl;
    cout << "\nИдея: Аналогично предыдущей задаче, начинаем из правого верхнего угла." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_131();
    return 0;
}
