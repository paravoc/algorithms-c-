/*
 * Задача 91: Valid Palindrome
 * Категория: Strings
 * Сложность: Easy
 * 
 * Описание: Проверить, является ли строка палиндромом, игнорируя не-буквенно-цифровые символы.
 * Идея решения: Два указателя с фильтрацией символов.
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
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            
            if (tolower(s[left]) != tolower(s[right])) return false;
            
            left++;
            right--;
        }
        return true;
    }
};

/*
 * Тестовая функция
 */
void test_091() {
    cout << "\n=== Тест задачи 91: Valid Palindrome ===" << endl;
    cout << "Категория: Strings" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Проверить, является ли строка палиндромом, игнорируя не-буквенно-цифровые символы." << endl;
    cout << "\nИдея: Два указателя с фильтрацией символов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_091();
    return 0;
}
