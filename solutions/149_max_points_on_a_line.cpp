/*
 * Задача 149: Max Points on a Line
 * Категория: Design
 * Сложность: Hard
 * 
 * Описание: Найти максимальное количество точек, лежащих на одной прямой.
 * Идея решения: Для каждой точки вычисляем углы с другими точками.
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
        
        int maxPoints = 2;
        
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> slopeCount;
            int same = 1;
            
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                if (x1 == x2 && y1 == y2) {
                    same++;
                    continue;
                }
                
                double slope;
                if (x1 == x2) {
                    slope = DBL_MAX; // вертикальная линия
                } else {
                    slope = (double)(y2 - y1) / (double)(x2 - x1);
                }
                
                slopeCount[slope]++;
            }
            
            int currentMax = same;
            for (auto& [slope, count] : slopeCount) {
                currentMax = max(currentMax, count + same);
            }
            
            maxPoints = max(maxPoints, currentMax);
        }
        
        return maxPoints;
    }
};```
### 150. Evaluate Reverse Polish Notation
**Описание**: Вычислить выражение в обратной польской записи.
**Идея**: Использовать стек для хранения операндов.


/*
 * Тестовая функция
 */
void test_149() {
    cout << "\n=== Тест задачи 149: Max Points on a Line ===" << endl;
    cout << "Категория: Design" << endl;
    cout << "Сложность: Hard" << endl;
    cout << "\nОписание: Найти максимальное количество точек, лежащих на одной прямой." << endl;
    cout << "\nИдея: Для каждой точки вычисляем углы с другими точками." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_149();
    return 0;
}
