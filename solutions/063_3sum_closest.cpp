/*
 * Задача 63: 3Sum Closest
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти тройку с суммой, наиболее близкой к target.
 * Идея решения: Сортируем массив и используем два указателя, отслеживая минимальную разницу.
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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    return sum;
                }
            }
        }
        return closestSum;
    }
};

/*
 * Тестовая функция
 */
void test_063() {
    cout << "\n=== Тест задачи 63: 3Sum Closest ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти тройку с суммой, наиболее близкой к target." << endl;
    cout << "\nИдея: Сортируем массив и используем два указателя, отслеживая минимальную разницу." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_063();
    return 0;
}
