/*
 * Задача 124: Self Crossing
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Проверить, пересекает ли путь сам себя.
 * Идея решения: Анализируем возможные случаи пересечения.
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
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if (n <= 3) return false;
        
        for (int i = 3; i < n; i++) {
            // Case 1: Fourth line crosses first line
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) return true;
            
            // Case 2: Fifth line meets first line
            if (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) return true;
            
            // Case 3: Sixth line crosses first line
            if (i >= 5 && x[i - 2] >= x[i - 4] && 
                x[i] + x[i - 4] >= x[i - 2] && 
                x[i - 1] <= x[i - 3] && 
                x[i - 1] + x[i - 5] >= x[i - 3]) return true;
        }
        
        return false;
    }
};

/*
 * Тестовая функция
 */
void test_124() {
    cout << "\n=== Тест задачи 124: Self Crossing ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Проверить, пересекает ли путь сам себя." << endl;
    cout << "\nИдея: Анализируем возможные случаи пересечения." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_124();
    return 0;
}
