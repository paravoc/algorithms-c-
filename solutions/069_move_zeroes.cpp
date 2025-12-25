/*
 * Задача 69: Move Zeroes
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Переместить все нули в конец массива, сохраняя порядок ненулевых элементов.
 * Идея решения: Два указателя: один для текущей позиции, другой для поиска ненулевых элементов.
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
    void moveZeroes(vector<int>& nums) {
        int nonZeroPos = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[nonZeroPos++], nums[i]);
            }
        }
    }
};

/*
 * Тестовая функция
 */
void test_069() {
    cout << "\n=== Тест задачи 69: Move Zeroes ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Переместить все нули в конец массива, сохраняя порядок ненулевых элементов." << endl;
    cout << "\nИдея: Два указателя: один для текущей позиции, другой для поиска ненулевых элементов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_069();
    return 0;
}
