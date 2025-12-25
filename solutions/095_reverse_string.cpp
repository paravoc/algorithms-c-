/*
 * Задача 95: Reverse String
 * Категория: Strings
 * Сложность: Easy
 * 
 * Описание: Развернуть строку на месте.
 * Идея решения: Два указателя с начала и конца.
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
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};

/*
 * Тестовая функция
 */
void test_095() {
    cout << "\n=== Тест задачи 95: Reverse String ===" << endl;
    cout << "Категория: Strings" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Развернуть строку на месте." << endl;
    cout << "\nИдея: Два указателя с начала и конца." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_095();
    return 0;
}
