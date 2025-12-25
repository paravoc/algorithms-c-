/*
 * Задача 54: Course Schedule II
 * Категория: Graphs
 * Сложность: Medium
 * 
 * Описание: Найти порядок прохождения курсов с учетом предварительных требований.
 * Идея решения: Топологическая сортировка с возвратом порядка.
 * 
 * Сгенерировано: 2025-12-25 15:15:03
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        
        vector<int> result;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);
            
            for (int neighbor : graph[course]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        if (result.size() != numCourses) return {};
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_054() {
    cout << "\n=== Тест задачи 54: Course Schedule II ===" << endl;
    cout << "Категория: Graphs" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти порядок прохождения курсов с учетом предварительных требований." << endl;
    cout << "\nИдея: Топологическая сортировка с возвратом порядка." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_054();
    return 0;
}
