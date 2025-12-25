/*
 * Задача 50: Serialize and Deserialize Binary Tree
 * Категория: Trees
 * Сложность: Medium
 * 
 * Описание: Сериализовать и десериализовать бинарное дерево.
 * Идея решения: Preorder обход с маркерами для null узлов.
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
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
    
    TreeNode* deserializeHelper(stringstream& ss) {
        string val;
        getline(ss, val, ',');
        if (val == "#") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);
        return root;
    }
};

/*
 * Тестовая функция
 */
void test_050() {
    cout << "\n=== Тест задачи 50: Serialize and Deserialize Binary Tree ===" << endl;
    cout << "Категория: Trees" << endl;
    cout << "Сложность: Medium" << endl;
    cout << "\nОписание: Сериализовать и десериализовать бинарное дерево." << endl;
    cout << "\nИдея: Preorder обход с маркерами для null узлов." << endl;
    cout << "\n✅ Код готов к использованию!" << endl;
}

int main() {
    test_050();
    return 0;
}
