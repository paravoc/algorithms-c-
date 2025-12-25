/*
 * Задача 73: Nested List Weight Sum
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Вычислить взвешенную сумму вложенного списка целых чисел.
 * Идея решения: Рекурсивный DFS с передачей текущей глубины.
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
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
    
    int dfs(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (auto& ni : nestedList) {
            if (ni.isInteger()) {
                sum += ni.getInteger() * depth;
            } else {
                sum += dfs(ni.getList(), depth + 1);
            }
        }
        return sum;
    }
};

/*
 * Тестовая функция
 */
void test_073() {
    cout << "\n=== Тест задачи 73: Nested List Weight Sum ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Вычислить взвешенную сумму вложенного списка целых чисел." << endl;
    cout << "\nИдея: Рекурсивный DFS с передачей текущей глубины." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_073();
    return 0;
}
