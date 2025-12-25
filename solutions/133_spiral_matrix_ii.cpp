/*
 * Задача 133: Spiral Matrix II
 * Категория: Matrix
 * Сложность: Medium
 * 
 * Описание: Заполнить матрицу числами от 1 до n² в спиральном порядке.
 * Идея решения: Аналогично предыдущей задаче, но заполняем числами.
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1;
        
        while (top <= bottom && left <= right) {
            // Верхняя строка
            for (int j = left; j <= right; j++) {
                matrix[top][j] = num++;
            }
            top++;
            
            // Правый столбец
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;
            
            if (top <= bottom) {
                // Нижняя строка
                for (int j = right; j >= left; j--) {
                    matrix[bottom][j] = num++;
                }
                bottom--;
            }
            
            if (left <= right) {
                // Левый столбец
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }
        
        return matrix;
    }
};

/*
 * Тестовая функция
 */
void test_133() {
    cout << "\n=== Тест задачи 133: Spiral Matrix II ===" << endl;
    cout << "Категория: Matrix" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Заполнить матрицу числами от 1 до n² в спиральном порядке." << endl;
    cout << "\nИдея: Аналогично предыдущей задаче, но заполняем числами." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_133();
    return 0;
}
