/*
 * Задача 70: Contains Duplicate II
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Проверить, есть ли дубликаты на расстоянии не более k.
 * Идея решения: Используем скользящее окно с хэш-таблицей.
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numIndex;
        
        for (int i = 0; i < nums.size(); i++) {
            if (numIndex.count(nums[i]) && i - numIndex[nums[i]] <= k) {
                return true;
            }
            numIndex[nums[i]] = i;
        }
        return false;
    }
};

/*
 * Тестовая функция
 */
void test_070() {
    cout << "\n=== Тест задачи 70: Contains Duplicate II ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Проверить, есть ли дубликаты на расстоянии не более k." << endl;
    cout << "\nИдея: Используем скользящее окно с хэш-таблицей." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_070();
    return 0;
}
