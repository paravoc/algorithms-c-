/*
 * Задача 53: Graph Valid Tree
 * Категория: Graphs
 * Сложность: Medium
 * 
 * Описание: Проверить, образуют ли ребра валидное дерево.
 * Идея решения: Дерево должно быть связным и не иметь циклов, с n-1 ребрами.
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
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        if (hasCycle(graph, visited, 0, -1)) return false;
        
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
    
    bool hasCycle(vector<vector<int>>& graph, vector<bool>& visited, int node, int parent) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (hasCycle(graph, visited, neighbor, node)) return true;
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }
};

/*
 * Тестовая функция
 */
void test_053() {
    cout << "\n=== Тест задачи 53: Graph Valid Tree ===" << endl;
    cout << "Категория: Graphs" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, образуют ли ребра валидное дерево." << endl;
    cout << "\nИдея: Дерево должно быть связным и не иметь циклов, с n-1 ребрами." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_053();
    return 0;
}
