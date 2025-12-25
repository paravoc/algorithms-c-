/*
 * Задача 102: Pow(x, n)
 * Категория: Maths (продолжение)
 * Сложность: Medium
 * 
 * Описание: Вычислить x в степени n.
 * Идея решения: Используем быстрое возведение в степень через двоичное разложение.
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

// Структуры данных для некоторых задач
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

// Структура для NestedInteger (для задач 73-74)
class NestedInteger {
public:
    bool isInteger() const { return false; }
    int getInteger() const { return 0; }
    const vector<NestedInteger>& getList() const { static vector<NestedInteger> empty; return empty; }
};

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        double current = x;
        
        for (long long i = N; i > 0; i /= 2) {
            if (i % 2 == 1) {
                result *= current;
            }
            current *= current;
        }
        return result;
    }
};

/*
 * Тестовые функции
 */
void test_102() {
    cout << "\n=== Тест для задачи 102: Pow(x, n) ===" << endl;
    cout << "Категория: Maths (продолжение)" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Вычислить x в степени n." << endl;
    cout << "\nИдея: Используем быстрое возведение в степень через двоичное разложение." << endl;
    
    // Здесь можно добавить тестовые примеры для конкретной задачи
    // Например, для Two Sum:
    // vector<int> nums = {2, 7, 11, 15};
    // int target = 9;
    // vector<int> result = twoSum(nums, target);
    // cout << "Результат: [" << result[0] << ", " << result[1] << "]" << endl;
    
    cout << "\n[Для этой задачи тесты требуют специфичных входных данных]" << endl;
    cout << "Смотрите реализацию выше для примера использования." << endl;
}

int main() {
    test_102();
    return 0;
}
