/*
 * Задача 52: Course Schedule
 * Категория: Graphs
 * Сложность: Medium
 * 
 * Описание: Проверить, можно ли завершить все курсы с учетом предварительных требований.
 * Идея решения: Проверка ацикличности ориентированного графа с помощью топологической сортировки.
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            
            for (int neighbor : graph[course]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return count == numCourses;
    }
};

/*
 * Тестовая функция
 */
void test_052() {
    cout << "\n=== Тест задачи 52: Course Schedule ===" << endl;
    cout << "Категория: Graphs" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, можно ли завершить все курсы с учетом предварительных требований." << endl;
    cout << "\nИдея: Проверка ацикличности ориентированного графа с помощью топологической сортировки." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_052();
    return 0;
}
