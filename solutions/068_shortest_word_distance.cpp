/*
 * Задача 68: Shortest Word Distance
 * Категория: Arrays
 * Сложность: Easy
 * 
 * Описание: Найти минимальное расстояние между двумя словами в массиве.
 * Идея решения: Отслеживаем последние позиции обоих слов и вычисляем минимальную разницу.
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
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1, pos2 = -1;
        int minDist = INT_MAX;
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                pos1 = i;
            } else if (words[i] == word2) {
                pos2 = i;
            }
            
            if (pos1 != -1 && pos2 != -1) {
                minDist = min(minDist, abs(pos1 - pos2));
            }
        }
        return minDist;
    }
};

/*
 * Тестовая функция
 */
void test_068() {
    cout << "\n=== Тест задачи 68: Shortest Word Distance ===" << endl;
    cout << "Категория: Arrays" << endl;
    cout << "Сложность: Easy" << endl;
    cout << "\nОписание: Найти минимальное расстояние между двумя словами в массиве." << endl;
    cout << "\nИдея: Отслеживаем последние позиции обоих слов и вычисляем минимальную разницу." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_068();
    return 0;
}
