#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include<cstring>

using namespace std;

// n에서 0을 몇번 출력하는지 표현하는 배열
int cache_0[41] = { 0 };
// n에서 1을 몇번 출력하는지 표현하는 배열
int cache_1[41] = { 0 };

int fibonacci_0(int n)
{
    // 0에서 1을 한번 출력
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 0;
    }

    if (cache_0[n] != 0)
    {
        return cache_0[n];
    }

    cache_0[n] = fibonacci_0(n - 1) + fibonacci_0(n - 2);
    return cache_0[n];
}

int fibonacci_1(int n)
{
    if (n == 0)
    {
        return 0;
    }
    // 1에서 1을 한번 출력
    else if (n == 1)
    {
        return 1;
    }

    if (cache_1[n] != 0)
    {
        return cache_1[n];
    }

    cache_1[n] = fibonacci_1(n - 1) + fibonacci_1(n - 2);
    return cache_1[n];
}

int main()
{
    int repeat;
    scanf_s("%d", &repeat);
    for (int i = 0; i < repeat; i++)
    {
        int temp;
        scanf_s("%d", &temp);

        printf("%d %d\n", fibonacci_0(temp), fibonacci_1(temp));
    }

    return 0;
}