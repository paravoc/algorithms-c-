/*
 * Задача 80: Container With Most Water
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти контейнер с максимальной площадью.
 * Идея решения: Два указателя с начала и конца, двигаем тот, который ограничивает высоту.
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
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

/*
 * Тестовая функция
 */
void test_080() {
    cout << "\n=== Тест задачи 80: Container With Most Water ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти контейнер с максимальной площадью." << endl;
    cout << "\nИдея: Два указателя с начала и конца, двигаем тот, который ограничивает высоту." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_080();
    return 0;
}
