#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// [][][][][][][][][][][][][][][][][] 순환 구조
class Queue
{
public:
    Queue()
    {
        _container.resize(10001);
    }

    void push(int value)
    {
        if (_size == _container.size())
        {
            int newSize = max(1, _size * 2);
            vector<int> newData;
            newData.resize(newSize);

            for (int i = 0; i < _size; i++)
            {
                int index = (_front + i) % _container.size();
                newData[i] = _container[index];
            }

            _container.swap(newData);
            _front = 0;
            _back = _size;
        }

        _container[_back] = value;
        _back = (_back + 1) % _container.size();
        _size++;
    }

    void pop()
    {
        if (_size == 0)
        {
            printf("-1\n");
            return;
        }
        printf("%d\n", _container[_front]);
        _front = (_front + 1) % _container.size();
        _size--;
    }

    int front()
    {
        if (_size == 0)
        {
            printf("-1\n");
            return -1;
        }
        printf("%d\n", _container[_front]);
        return _container[_front];
    }

    int back()
    {
        if (_size == 0)
        {
            printf("-1\n");
            return -1;
        }
        printf("%d\n", _container[_back - 1]);
        return _container[_back - 1];
    }

    bool empty()
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

    int size()
    {
        printf("%d\n", _size);
        return _size;
    }

private:
    vector<int> _container;

    int _front = 0;
    int _back = 0;
    int _size = 0;
};

int main()
{
    Queue q;

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
            q.push(value);
        }
        else if (command == "pop")
        {
            q.pop();
        }
        else if (command == "size")
        {
            q.size();
        }
        else if (command == "empty")
        {
            q.empty();
        }
        else if (command == "front")
        {
            q.front();
        }
        else if (command == "back")
        {
            q.back();
        }
    }


    return 0;
}