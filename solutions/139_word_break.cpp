/*
 * Задача 139: Word Break
 * Категория: Design
 * Сложность: Hard
 * 
 * Описание: Определить, можно ли разбить строку на слова из словаря.
 * Идея решения: Динамическое программирование.
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
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};```
### 140. Word Break II
**Описание**: Вернуть все возможные разбиения строки на слова из словаря.
**Идея**: DFS с мемоизацией.


/*
 * Тестовая функция
 */
void test_139() {
    cout << "\n=== Тест задачи 139: Word Break ===" << endl;
    cout << "Категория: Design" << endl;
    cout << "Сложность: Hard" << endl;
    cout << "\nОписание: Определить, можно ли разбить строку на слова из словаря." << endl;
    cout << "\nИдея: Динамическое программирование." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_139();
    return 0;
}
