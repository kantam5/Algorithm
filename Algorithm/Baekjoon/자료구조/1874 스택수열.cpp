#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// 지금 꺼내야하는 수가 스택의 top이 아닌 안에 있는 경우
bool in_stack(stack<int> s, int num)
{
    int count = 0;

    while (s.size() != 0 && s.top() != num)
    {
        s.pop();
        count++;
    }

    return count > 0;
}

int main()
{
    int repeat;
    scanf("%d", &repeat);

    queue<int> arr;
    for (int i = 0; i < repeat; i++)
    {
        int temp;
        scanf("%d", &temp);
        arr.push(temp);
    }

    // 맨 위에것이 해당하는 숫자가 아니라면 push, 맞다면 pop
    vector<char> result;
    stack<int> s;
    s.push(0);
    int count = 0;
    while (!arr.empty())
    {
        int temp = arr.front();
        arr.pop();

        while (s.top() != temp)
        {
            if (count > temp)
            {
                if (in_stack(s, temp))
                {
                    printf("NO\n");
                    return 0;
                }
            }

            count++;
            s.push(count);
            result.push_back('+');
        }

        s.pop();
        result.push_back('-');
    }

    for (int i = 0; i < result.size(); i++)
    {
        printf("%c\n", result[i]);
    }

    return 0;
}