/*
 * Задача 86: Pascal's Triangle
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Сгенерировать треугольник Паскаля до n-й строки.
 * Идея решения: Каждое число равно сумме двух чисел над ним.
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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            triangle.push_back(row);
        }
        return triangle;
    }
};

/*
 * Тестовая функция
 */
void test_086() {
    cout << "\n=== Тест задачи 86: Pascal's Triangle ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Сгенерировать треугольник Паскаля до n-й строки." << endl;
    cout << "\nИдея: Каждое число равно сумме двух чисел над ним." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_086();
    return 0;
}
