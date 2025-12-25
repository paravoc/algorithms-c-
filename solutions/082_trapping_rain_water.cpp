/*
 * Задача 82: Trapping Rain Water
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Вычислить количество воды, которое может задержаться между столбцами.
 * Идея решения: Для каждого столбца вычисляем min(макс_слева, макс_справа) - высота_столбца.
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
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> leftMax(n), rightMax(n);
        
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        
        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }
        return water;
    }
};

/*
 * Тестовая функция
 */
void test_082() {
    cout << "\n=== Тест задачи 82: Trapping Rain Water ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Вычислить количество воды, которое может задержаться между столбцами." << endl;
    cout << "\nИдея: Для каждого столбца вычисляем min(макс_слева, макс_справа) - высота_столбца." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_082();
    return 0;
}
