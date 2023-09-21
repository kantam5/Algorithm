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

using namespace std;

#define MOD 1000000007

map<long long, vector<vector<long long>>> cache;

vector<vector<long long>> matrix = {
    {1, 1},
    {1, 0}
};

vector<vector<long long>> mulMatrix(vector<vector<long long>> m1, vector<vector<long long>> m2)
{
    vector<vector<long long>> outM = {
        {0, 0},
        {0, 0}
    };

    outM[0][0] = (m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0]) % MOD;
    outM[0][1] = (m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1]) % MOD;
    outM[1][0] = (m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0]) % MOD;
    outM[1][1] = (m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1]) % MOD;

    return outM;
}

vector<vector<long long>> fibonacci(long long n)
{
    if (n == 1)
    {
        return matrix;
    }

    // cache가 있을 때는 cache반환
    if (!cache[n].empty())
    {
        return cache[n];
    }

    if (n % 2 == 0)
    {
        cache[n] = mulMatrix(fibonacci(n / 2), fibonacci(n / 2));
        return cache[n];
    }
    else
    {
        cache[n] = mulMatrix(fibonacci(n - 1), fibonacci(1));
        return cache[n];
    }
}

int main()
{
    long long n;
    cin >> n;

    cache[1] = matrix;

    vector<vector<long long>> answer = fibonacci(n);

    cout << answer[0][1];

    return 0;
}