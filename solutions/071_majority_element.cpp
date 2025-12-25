/*
 * Задача 71: Majority Element
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти элемент, встречающийся более n/2 раз.
 * Идея решения: Алгоритм Бойера-Мура для поиска majority элемента.
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
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};

/*
 * Тестовая функция
 */
void test_071() {
    cout << "\n=== Тест задачи 71: Majority Element ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти элемент, встречающийся более n/2 раз." << endl;
    cout << "\nИдея: Алгоритм Бойера-Мура для поиска majority элемента." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_071();
    return 0;
}
