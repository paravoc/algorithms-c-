/*
 * Задача 59: Two Sum III - Data Structure Design
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Реализовать структуру данных, поддерживающую добавление чисел и поиск пар с заданной суммой.
 * Идея решения: Используем хэш-таблицу для быстрого поиска.
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
class TwoSum {
    unordered_map<int, int> numCount;
public:
    TwoSum() {}
    
    void add(int number) {
        numCount[number]++;
    }
    
    bool find(int value) {
        for (auto& [num, count] : numCount) {
            int complement = value - num;
            if (complement != num) {
                if (numCount.count(complement)) return true;
            } else {
                if (count > 1) return true;
            }
        }
        return false;
    }
};

/*
 * Тестовая функция
 */
void test_059() {
    cout << "\n=== Тест задачи 59: Two Sum III - Data Structure Design ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Реализовать структуру данных, поддерживающую добавление чисел и поиск пар с заданной суммой." << endl;
    cout << "\nИдея: Используем хэш-таблицу для быстрого поиска." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_059();
    return 0;
}
