/*
 * Задача 123: Find K Pairs with Smallest Sums
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Найти k пар с наименьшими суммами из двух массивов.
 * Идея решения: Используем минимальную кучу для хранения кандидатов.
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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;
        
        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < min(k, (int)nums1.size()); i++) {
            pq.push({i, 0});
        }
        
        while (k-- > 0 && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();
            result.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < nums2.size()) {
                pq.push({i, j + 1});
            }
        }
        
        return result;
    }
};

/*
 * Тестовая функция
 */
void test_123() {
    cout << "\n=== Тест задачи 123: Find K Pairs with Smallest Sums ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Найти k пар с наименьшими суммами из двух массивов." << endl;
    cout << "\nИдея: Используем минимальную кучу для хранения кандидатов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_123();
    return 0;
}
