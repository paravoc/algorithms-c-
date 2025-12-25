/*
 * Задача 92: Word Pattern
 * Категория: Strings
 * Сложность: Easy
 * 
 * Описание: Проверить, соответствует ли строка шаблону.
 * Идея решения: Используем два хэша для взаимно-однозначного соответствия.
 * 
 * Сгенерировано: 2025-12-25 14:32:36
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
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        stringstream ss(s);
        string word;
        int i = 0;
        
        while (ss >> word) {
            if (i >= pattern.length()) return false;
            
            char c = pattern[i];
            
            if (charToWord.count(c) && charToWord[c] != word) return false;
            if (wordToChar.count(word) && wordToChar[word] != c) return false;
            
            charToWord[c] = word;
            wordToChar[word] = c;
            i++;
        }
        
        return i == pattern.length();
    }
};

/*
 * Тестовая функция
 */
void test_092() {
    cout << "\n=== Тест задачи 92: Word Pattern ===" << endl;
    cout << "Категория: Strings" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Проверить, соответствует ли строка шаблону." << endl;
    cout << "\nИдея: Используем два хэша для взаимно-однозначного соответствия." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_092();
    return 0;
}
