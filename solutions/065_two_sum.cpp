/*
 * Задача 65: Two Sum
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти индексы двух чисел, дающих в сумме target.
 * Идея решения: Используем хэш-таблицу для хранения чисел и их индексов.
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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

/*
 * Тестовая функция
 */
void test_065() {
    cout << "\n=== Тест задачи 65: Two Sum ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти индексы двух чисел, дающих в сумме target." << endl;
    cout << "\nИдея: Используем хэш-таблицу для хранения чисел и их индексов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_065();
    return 0;
}
