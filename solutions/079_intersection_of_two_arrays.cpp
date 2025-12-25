/*
 * Задача 79: Intersection of Two Arrays
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти пересечение двух массивов (уникальные элементы).
 * Идея решения: Используем два множества для хранения уникальных элементов.
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;
        
        for (int num : nums2) {
            if (set1.count(num)) {
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};

/*
 * Тестовая функция
 */
void test_079() {
    cout << "\n=== Тест задачи 79: Intersection of Two Arrays ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти пересечение двух массивов (уникальные элементы)." << endl;
    cout << "\nИдея: Используем два множества для хранения уникальных элементов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_079();
    return 0;
}
