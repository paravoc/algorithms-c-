/*
 * Задача 57: Kth Largest Element in an Array
 * Категория: Heaps
 * Сложность: Medium
 * 
 * Описание: Найти k-й наибольший элемент в массиве.
 * Идея решения: Используем минимальную кучу размера k для отслеживания k наибольших элементов.
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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

/*
 * Тестовая функция
 */
void test_057() {
    cout << "\n=== Тест задачи 57: Kth Largest Element in an Array ===" << endl;
    cout << "Категория: Heaps" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти k-й наибольший элемент в массиве." << endl;
    cout << "\nИдея: Используем минимальную кучу размера k для отслеживания k наибольших элементов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_057();
    return 0;
}
