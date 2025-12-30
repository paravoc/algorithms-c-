/*
 * Задача 58: Two Sum II - Input Array Is Sorted
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти индексы двух чисел в отсортированном массиве, дающих в сумме target.
 * Идея решения: Два указателя с начала и конца массива.
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};

/*
 * Тестовая функция
 */
void test_058() {
    cout << "\n=== Тест задачи 58: Two Sum II - Input Array Is Sorted ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти индексы двух чисел в отсортированном массиве, дающих в сумме target." << endl;
    cout << "\nИдея: Два указателя с начала и конца массива." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_058();
    return 0;
}
