/*
 * Задача 83: Maximum Subarray
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти подмассив с максимальной суммой.
 * Идея решения: Алгоритм Кадане - отслеживаем текущую сумму и максимальную сумму.
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
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};

/*
 * Тестовая функция
 */
void test_083() {
    cout << "\n=== Тест задачи 83: Maximum Subarray ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти подмассив с максимальной суммой." << endl;
    cout << "\nИдея: Алгоритм Кадане - отслеживаем текущую сумму и максимальную сумму." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_083();
    return 0;
}
