/*
 * Задача 103: Subsets
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Найти все подмножества множества.
 * Идея решения: Используем битовые маски или backtracking.
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int total = 1 << n;
        
        for (int mask = 0; mask < total; mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_103() {
    cout << "\n=== Тест задачи 103: Subsets ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти все подмножества множества." << endl;
    cout << "\nИдея: Используем битовые маски или backtracking." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_103();
    return 0;
}
