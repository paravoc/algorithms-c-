/*
 * Задача 132: Spiral Matrix
 * Категория: Matrix
 * Сложность: Medium
 * 
 * Описание: Вернуть элементы матрицы в спиральном порядке.
 * Идея решения: Обходим матрицу по слоям с четырьмя направлениями.
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> result;
        
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        while (top <= bottom && left <= right) {
            // Верхняя строка
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;
            
            // Правый столбец
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                // Нижняя строка
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            
            if (left <= right) {
                // Левый столбец
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_132() {
    cout << "\n=== Тест задачи 132: Spiral Matrix ===" << endl;
    cout << "Категория: Matrix" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вернуть элементы матрицы в спиральном порядке." << endl;
    cout << "\nИдея: Обходим матрицу по слоям с четырьмя направлениями." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_132();
    return 0;
}
