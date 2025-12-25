/*
 * Задача 87: Pascal's Triangle II
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Вернуть k-ю строку треугольника Паскаля.
 * Идея решения: Генерируем строку итеративно, используя только O(k) памяти.
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
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }
        return row;
    }
};

/*
 * Тестовые функции
 */
void test_087() {
    cout << "\n=== Тест для задачи 87: Pascal's Triangle II ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Вернуть k-ю строку треугольника Паскаля." << endl;
    cout << "\nИдея: Генерируем строку итеративно, используя только O(k) памяти." << endl;
    
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
    test_087();
    return 0;
}
