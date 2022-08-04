#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include<cstring>

using namespace std;


int main()
{
    const int MAX = 1000001;
    bool prime[MAX];

    memset(prime, false, MAX);
    prime[2] = true;

    for (int i = 3; i < MAX; i += 2)
    {
        // 홀수를 일단 true로 나중에 소수 체크
        prime[i] = true;
    }
    // 홀수번만 체크
    for (int i = 3;; i += 2)
    {
        // i가 소수인 경우엔 배수들을 false로
        if (prime[i] == true)
        {
            int j = i * i;
            if (j >= MAX)
            {
                break;
            }

            for (i *= 2; j < MAX; j += i)
            {
                prime[j] = false;
            }
            i /= 2;
        }
    }

    int num1;
    int num2;
    scanf_s("%d %d", &num1, &num2);

    for (int i = num1; i <= num2; i++)
    {
        if (prime[i] == true)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}