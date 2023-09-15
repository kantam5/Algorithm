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

struct node
{
    int data;
    node* left;
    node* right;
};

struct bst
{
    node* root = nullptr;

public:
    void insert(int value)
    {
        if (!root)
            root = new node{ value, NULL, NULL };
        else
            insert_impl(root, value);
    }

private:
    void insert_impl(node* current, int value)
    {
        if (value < current->data)
        {
            if (!current->left)
                current->left = new node{ value, NULL, NULL };
            else
                insert_impl(current->left, value);
        }
        else
        {
            if (!current->right)
                current->right = new node{ value, NULL, NULL };
            else
                insert_impl(current->right, value);
        }
    }

public:
    void postOrder(node* start)
    {
        if (!start)
            return;
        postOrder(start->left);
        postOrder(start->right);
        cout << start->data << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bst tree;
    int temp;

    while (cin >> temp)
    {
        tree.insert(temp);
    }

    tree.postOrder(tree.root);

    return 0;
}