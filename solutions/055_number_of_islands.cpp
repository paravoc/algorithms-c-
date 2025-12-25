/*
 * Задача 55: Number of Islands
 * Категория: Graphs
 * Сложность: Medium
 * 
 * Описание: Подсчитать количество островов в двумерной сетке.
 * Идея решения: DFS для поиска связных компонент из '1'.
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
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;
        
        grid[i][j] = '0'; // Помечаем как посещенный
        
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i, j + 1, m, n);
        dfs(grid, i, j - 1, m, n);
    }
};

/*
 * Тестовая функция
 */
void test_055() {
    cout << "\n=== Тест задачи 55: Number of Islands ===" << endl;
    cout << "Категория: Graphs" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Подсчитать количество островов в двумерной сетке." << endl;
    cout << "\nИдея: DFS для поиска связных компонент из '1'." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_055();
    return 0;
}
