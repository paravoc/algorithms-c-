/*
 * Задача 72: Remove Duplicates from Sorted Array
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Удалить дубликаты из отсортированного массива на месте.
 * Идея решения: Два указателя: один для уникальных элементов, другой для обхода массива.
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
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int uniquePos = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[uniquePos]) {
                nums[++uniquePos] = nums[i];
            }
        }
        return uniquePos + 1;
    }
};

/*
 * Тестовая функция
 */
void test_072() {
    cout << "\n=== Тест задачи 72: Remove Duplicates from Sorted Array ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Удалить дубликаты из отсортированного массива на месте." << endl;
    cout << "\nИдея: Два указателя: один для уникальных элементов, другой для обхода массива." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_072();
    return 0;
}
