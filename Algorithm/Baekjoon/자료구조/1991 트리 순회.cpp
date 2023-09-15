#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <memory.h>
#include <unordered_map>
#include <cmath>
#include <deque>

using namespace std;

struct Node
{
    char data;
    Node* left = NULL;
    Node* right = NULL;
};

void preorder(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }

    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}

void postorder(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node alphabet[26];
    for (int i = 0; i < 26; i++)
    {
        alphabet[i].data = (char)(65 + i);
    }

    int N;
    cin >> N;

    while (N--)
    {
        char parent;
        char left;
        char right;

        cin >> parent >> left >> right;

        if (left != '.')
        {
            alphabet[(int)parent - 65].left = &alphabet[(int)left - 65];
        }
        if (right != '.')
        {
            alphabet[(int)parent - 65].right = &alphabet[(int)right - 65];
        }
    }

    preorder(&alphabet[0]);
    cout << '\n';
    inorder(&alphabet[0]);
    cout << '\n';
    postorder(&alphabet[0]);
    cout << '\n';

    return 0;
}