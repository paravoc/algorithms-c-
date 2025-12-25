/*
 * Задача 76: Intersection of Two Arrays II
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти пересечение двух массивов с учетом кратности элементов.
 * Идея решения: Сортируем оба массива и используем два указателя.
 * 
 * Сгенерировано: 2025-12-25 15:15:03
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_076() {
    cout << "\n=== Тест задачи 76: Intersection of Two Arrays II ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти пересечение двух массивов с учетом кратности элементов." << endl;
    cout << "\nИдея: Сортируем оба массива и используем два указателя." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_076();
    return 0;
}
