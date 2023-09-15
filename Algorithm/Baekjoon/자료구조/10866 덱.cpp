#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// [][][][][][][][][][][][][][][][][] 순환 구조


class Deque
{
public:
    Deque()
    {
        _container.resize(10);
    }

    void push_front(int value)
    {
        _container[_front] = value;
        _front = (_front + _container.size() - 1) % _container.size();
        _size++;
    }

    void push_back(int value)
    {
        _back = (_back + 1) % _container.size();
        _container[_back] = value;
        _size++;
    }

    void pop_front()
    {
        if (_size == 0)
        {
            printf("-1\n");
            return;
        }
        printf("%d\n", _container[(_front + 1) % _container.size()]);
        _front = (_front + 1) % _container.size();
        _size--;
    }

    void pop_back()
    {
        if (_size == 0)
        {
            printf("-1\n");
            return;
        }
        printf("%d\n", _container[_back]);
        _back = (_back + _container.size() - 1) % _container.size();
        _size--;
    }

    int front()
    {
        if (_size == 0)
        {
            printf("-1\n");
            return -1;
        }
        printf("%d\n", _container[(_front + 1) % _container.size()]);
        return _container[(_front + 1) % _container.size()];
    }

    int back()
    {
        if (_size == 0)
        {
            printf("-1\n");
            return -1;
        }
        printf("%d\n", _container[_back]);
        return _container[_back];
    }

    int size()
    {
        printf("%d\n", _size);
        return _size;
    }

    int empty()
    {
        if (_size == 0)
        {
            printf("1\n");
            return 1;
        }
        else
        {
            printf("0\n");
            return 0;
        }
    }

private:
    vector<int> _container;

    int _front = 0;
    int _back = 0;
    int _size = 0;
};

int main()
{
    Deque Dq;

    int repeat;
    scanf_s("%d", &repeat);
    for (int i = 0; i < repeat; i++)
    {
        string command;
        cin >> command;

        if (command == "push_front")
        {
            int value;
            scanf_s("%d", &value);
            Dq.push_front(value);
        }
        else if (command == "push_back")
        {
            int value;
            scanf_s("%d", &value);
            Dq.push_back(value);
        }
        else if (command == "pop_front")
        {
            Dq.pop_front();
        }
        else if (command == "pop_back")
        {
            Dq.pop_back();
        }
        else if (command == "size")
        {
            Dq.size();
        }
        else if (command == "empty")
        {
            Dq.empty();
        }
        else if (command == "front")
        {
            Dq.front();
        }
        else if (command == "back")
        {
            Dq.back();
        }
    }


    return 0;
}