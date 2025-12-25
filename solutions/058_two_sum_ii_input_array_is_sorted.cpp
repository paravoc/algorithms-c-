/*
 * Задача 58: Two Sum II - Input Array Is Sorted
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти индексы двух чисел в отсортированном массиве, дающих в сумме target.
 * Идея решения: Два указателя с начала и конца массива.
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};

/*
 * Тестовые функции
 */
void test_058() {
    cout << "\n=== Тест для задачи 58: Two Sum II - Input Array Is Sorted ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти индексы двух чисел в отсортированном массиве, дающих в сумме target." << endl;
    cout << "\nИдея: Два указателя с начала и конца массива." << endl;
    
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
    test_058();
    return 0;
}
