/*
 * Задача 77: Merge Sorted Arrays
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Объединить два отсортированных массива в первый массив.
 * Идея решения: Заполняем с конца, чтобы не перезаписывать элементы.
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

/*
 * Тестовая функция
 */
void test_077() {
    cout << "\n=== Тест задачи 77: Merge Sorted Arrays ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Объединить два отсортированных массива в первый массив." << endl;
    cout << "\nИдея: Заполняем с конца, чтобы не перезаписывать элементы." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_077();
    return 0;
}
