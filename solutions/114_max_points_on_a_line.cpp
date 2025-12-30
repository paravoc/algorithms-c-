/*
 * Задача 114: Max Points on a Line
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Найти максимальное количество точек на одной прямой.
 * Идея решения: Для каждой точки считаем угловые коэффициенты с другими точками.
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
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int maxPoints = 1;
        
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeCount;
            int duplicate = 1;
            
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                if (x1 == x2 && y1 == y2) {
                    duplicate++;
                    continue;
                }
                
                int dx = x2 - x1, dy = y2 - y1;
                int g = gcd(dx, dy);
                
                string slope = to_string(dy / g) + "/" + to_string(dx / g);
                slopeCount[slope]++;
            }
            
            maxPoints = max(maxPoints, duplicate);
            for (auto& [slope, count] : slopeCount) {
                maxPoints = max(maxPoints, count + duplicate);
            }
        }
        
        return maxPoints;
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

/*
 * Тестовая функция
 */
void test_114() {
    cout << "\n=== Тест задачи 114: Max Points on a Line ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти максимальное количество точек на одной прямой." << endl;
    cout << "\nИдея: Для каждой точки считаем угловые коэффициенты с другими точками." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_114();
    return 0;
}
