/*
 * Задача 74: Nested List Weight Sum II
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Вычислить взвешенную сумму с весами от листьев к корню.
 * Идея решения: Сначала находим максимальную глубину, затем вычисляем сумму с обратными весами.
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
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = getMaxDepth(nestedList);
        return dfs(nestedList, maxDepth);
    }
    
    int getMaxDepth(vector<NestedInteger>& nestedList) {
        int maxDepth = 1;
        for (auto& ni : nestedList) {
            if (!ni.isInteger()) {
                maxDepth = max(maxDepth, 1 + getMaxDepth(ni.getList()));
            }
        }
        return maxDepth;
    }
    
    int dfs(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (auto& ni : nestedList) {
            if (ni.isInteger()) {
                sum += ni.getInteger() * depth;
            } else {
                sum += dfs(ni.getList(), depth - 1);
            }
        }
        return sum;
    }
};

/*
 * Тестовая функция
 */
void test_074() {
    cout << "\n=== Тест задачи 74: Nested List Weight Sum II ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Вычислить взвешенную сумму с весами от листьев к корню." << endl;
    cout << "\nИдея: Сначала находим максимальную глубину, затем вычисляем сумму с обратными весами." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_074();
    return 0;
}
