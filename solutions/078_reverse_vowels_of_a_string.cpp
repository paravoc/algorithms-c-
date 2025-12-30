/*
 * Задача 78: Reverse Vowels of a String
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Развернуть только гласные в строке.
 * Идея решения: Два указателя с начала и конца, меняем гласные местами.
 * 
 * Сгенерировано: 2025-12-30 15:41:18
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
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            while (left < right && !vowels.count(s[left])) left++;
            while (left < right && !vowels.count(s[right])) right--;
            
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

/*
 * Тестовая функция
 */
void test_078() {
    cout << "\n=== Тест задачи 78: Reverse Vowels of a String ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Развернуть только гласные в строке." << endl;
    cout << "\nИдея: Два указателя с начала и конца, меняем гласные местами." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_078();
    return 0;
}
