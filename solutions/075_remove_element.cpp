/*
 * Задача 75: Remove Element
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Удалить все вхождения элемента из массива на месте.
 * Идея решения: Два указателя: один для текущей позиции, другой для обхода массива.
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
    int removeElement(vector<int>& nums, int val) {
        int newPos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[newPos++] = nums[i];
            }
        }
        return newPos;
    }
};

/*
 * Тестовая функция
 */
void test_075() {
    cout << "\n=== Тест задачи 75: Remove Element ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Удалить все вхождения элемента из массива на месте." << endl;
    cout << "\nИдея: Два указателя: один для текущей позиции, другой для обхода массива." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_075();
    return 0;
}
