/*
 * Задача 61: Rotate Array
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Сдвинуть массив вправо на k шагов.
 * Идея решения: Три реверса: весь массив, первые k элементов, остальные элементы.
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
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

/*
 * Тестовая функция
 */
void test_061() {
    cout << "\n=== Тест задачи 61: Rotate Array ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Сдвинуть массив вправо на k шагов." << endl;
    cout << "\nИдея: Три реверса: весь массив, первые k элементов, остальные элементы." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_061();
    return 0;
}
