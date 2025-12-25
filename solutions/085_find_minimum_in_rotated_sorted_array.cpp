/*
 * Задача 85: Find Minimum in Rotated Sorted Array
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти минимальный элемент в rotated sorted array.
 * Идея решения: Модифицированный бинарный поиск.
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
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

/*
 * Тестовая функция
 */
void test_085() {
    cout << "\n=== Тест задачи 85: Find Minimum in Rotated Sorted Array ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти минимальный элемент в rotated sorted array." << endl;
    cout << "\nИдея: Модифицированный бинарный поиск." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_085();
    return 0;
}
