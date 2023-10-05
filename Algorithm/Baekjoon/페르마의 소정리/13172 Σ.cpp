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
#include <climits>

const int MOD = 1'000'000'007;

using namespace std;

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M;
    long long answer = 0;

    cin >> M;

    while (M--)
    {
        long long N, S;
        cin >> N >> S;

        // b^(-1)�� b^(MOD - 2)�̹Ƿ� 
        // b^(MOD - 2)�� ���ϰ� S�� ���ؼ� MOD����
        answer += power(N, MOD - 2, MOD) * S % MOD;
    }

    answer %= MOD;
    cout << answer;

    return 0;
}