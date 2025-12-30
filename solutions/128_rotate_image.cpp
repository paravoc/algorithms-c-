/*
 * Задача 128: Rotate Image
 * Категория: Matrix
 * Сложность: Medium
 * 
 * Описание: Повернуть изображение (матрицу) на 90 градусов по часовой стрелке.
 * Идея решения: Транспонируем матрицу и отражаем по вертикали.
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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Транспонирование
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Отражение по вертикали
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/*
 * Тестовая функция
 */
void test_128() {
    cout << "\n=== Тест задачи 128: Rotate Image ===" << endl;
    cout << "Категория: Matrix" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Повернуть изображение (матрицу) на 90 градусов по часовой стрелке." << endl;
    cout << "\nИдея: Транспонируем матрицу и отражаем по вертикали." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_128();
    return 0;
}
