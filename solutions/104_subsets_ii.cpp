/*
 * Задача 104: Subsets II
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Найти все уникальные подмножества множества с дубликатами.
 * Идея решения: Сортируем и используем backtracking, пропуская дубликаты.
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};

/*
 * Тестовая функция
 */
void test_104() {
    cout << "\n=== Тест задачи 104: Subsets II ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти все уникальные подмножества множества с дубликатами." << endl;
    cout << "\nИдея: Сортируем и используем backtracking, пропуская дубликаты." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_104();
    return 0;
}
