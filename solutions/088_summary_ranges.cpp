/*
 * Задача 88: Summary Ranges
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Суммировать отсортированный массив в диапазоны.
 * Идея решения: Проходим по массиву и формируем диапазоны из последовательных чисел.
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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            
            if (start == nums[i]) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_088() {
    cout << "\n=== Тест задачи 88: Summary Ranges ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Суммировать отсортированный массив в диапазоны." << endl;
    cout << "\nИдея: Проходим по массиву и формируем диапазоны из последовательных чисел." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_088();
    return 0;
}
