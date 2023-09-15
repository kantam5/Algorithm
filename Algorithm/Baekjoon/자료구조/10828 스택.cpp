#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Stack
{
public:
    void push(int value)
    {
        _container.push_back(value);
    }

    void pop()
    {
        if (_container.empty())
        {
            printf("-1\n");
            return;
        }
        printf("%d\n", _container.back());
        _container.pop_back();
    }

    int top()
    {
        if (_container.empty())
        {
            printf("-1\n");
            return -1;
        }
        printf("%d\n", _container.back());
        return _container.back();
    }

    bool empty()
    {
        printf("%d\n", _container.empty());
        return _container.empty();
    }

    size_t size()
    {
        printf("%d\n", _container.size());
        return _container.size();
    }

private:
    // vector<T> _container;
    vector<int> _container;
};

int main()
{
    Stack s;

    int repeat;
    scanf_s("%d", &repeat);
    for (int i = 0; i < repeat; i++)
    {
        string command;
        cin >> command;

        if (command == "push")
        {
            int value;
            scanf_s("%d", &value);
            s.push(value);
        }
        else if (command == "pop")
        {
            s.pop();
        }
        else if (command == "size")
        {
            s.size();
        }
        else if (command == "empty")
        {
            s.empty();
        }
        else if (command == "top")
        {
            s.top();
        }
    }


    return 0;
}