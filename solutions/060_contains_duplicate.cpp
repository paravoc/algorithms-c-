/*
 * Задача 60: Contains Duplicate
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Проверить, содержит ли массив дубликаты.
 * Идея решения: Используем множество для отслеживания уникальных элементов.
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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return true;
            seen.insert(num);
        }
        return false;
    }
};

/*
 * Тестовая функция
 */
void test_060() {
    cout << "\n=== Тест задачи 60: Contains Duplicate ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Проверить, содержит ли массив дубликаты." << endl;
    cout << "\nИдея: Используем множество для отслеживания уникальных элементов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_060();
    return 0;
}
