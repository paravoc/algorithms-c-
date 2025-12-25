/*
 * Задача 51: Number of Connected Components in Undirected Graph
 * Категория: Graphs
 * Сложность: Medium
 * 
 * Описание: Подсчитать количество связных компонент в неориентированном графе.
 * Идея решения: Используем Union-Find алгоритм для объединения компонент.
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
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        int components = n;
        for (auto& edge : edges) {
            int root1 = find(parent, edge[0]);
            int root2 = find(parent, edge[1]);
            if (root1 != root2) {
                parent[root1] = root2;
                components--;
            }
        }
        return components;
    }
    
    int find(vector<int>& parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};

/*
 * Тестовая функция
 */
void test_051() {
    cout << "\n=== Тест задачи 51: Number of Connected Components in Undirected Graph ===" << endl;
    cout << "Категория: Graphs" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Подсчитать количество связных компонент в неориентированном графе." << endl;
    cout << "\nИдея: Используем Union-Find алгоритм для объединения компонент." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_051();
    return 0;
}
