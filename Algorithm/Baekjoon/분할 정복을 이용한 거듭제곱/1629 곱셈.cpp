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

long long solution(long long A, long long B, long long C)
{
    long long result = 1;

    while (B > 0)
    {
        if (B % 2 == 1)
        {
            result = (result * A) % C;
            // result = ((result % C) * (A % C)) % C;
        }
        B /= 2;

        A = ((A % C) * (A % C)) % C;
    }

    return result;
}

// a�� b�� ���ϰ� c�� ���� ��
long long power(long long a, long long b, long long c)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a % c;
    }

    long long temp = power(a, b / 2, c);
    temp = temp * temp % c;

    // b�� ¦�� �� ���
    if (b % 2 == 0)
    {
        return temp;
    }
    // b�� Ȧ�� �� ���
    else
    {
        return temp * a % c;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A;
    long long B;
    long long C;
    cin >> A >> B >> C;

    cout << solution(A, B, C) << endl;

    return 0;
}