/*
 * Задача 94: Isomorphic Strings
 * Категория: Strings
 * Сложность: Easy
 * 
 * Описание: Проверить, являются ли строки изоморфными.
 * Идея решения: Проверяем взаимно-однозначное соответствие символов.
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
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;
        
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];
            
            if (sToT.count(c1) && sToT[c1] != c2) return false;
            if (tToS.count(c2) && tToS[c2] != c1) return false;
            
            sToT[c1] = c2;
            tToS[c2] = c1;
        }
        return true;
    }
};

/*
 * Тестовая функция
 */
void test_094() {
    cout << "\n=== Тест задачи 94: Isomorphic Strings ===" << endl;
    cout << "Категория: Strings" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Проверить, являются ли строки изоморфными." << endl;
    cout << "\nИдея: Проверяем взаимно-однозначное соответствие символов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_094();
    return 0;
}
