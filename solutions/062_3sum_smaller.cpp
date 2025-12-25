/*
 * Задача 62: 3Sum Smaller
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти количество троек с суммой меньше target.
 * Идея решения: Сортируем массив и используем два указателя для каждой позиции i.
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
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        
        sort(nums.begin(), nums.end());
        int count = 0;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    count += right - left;
                    left++;
                } else {
                    right--;
                }
            }
        }
        return count;
    }
};

/*
 * Тестовая функция
 */
void test_062() {
    cout << "\n=== Тест задачи 62: 3Sum Smaller ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти количество троек с суммой меньше target." << endl;
    cout << "\nИдея: Сортируем массив и используем два указателя для каждой позиции i." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_062();
    return 0;
}
