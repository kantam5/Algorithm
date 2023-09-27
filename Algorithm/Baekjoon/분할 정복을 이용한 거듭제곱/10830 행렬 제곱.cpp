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

#define MOD 1000

using namespace std;

int N;
long long B;
map<long long, vector<vector<long long>>> cache;
vector<vector<long long>> matrix;

vector<vector<long long>> mulMatrix(vector<vector<long long>> m1, vector<vector<long long>> m2)
{
    vector<vector<long long>> outMatrix;
    outMatrix.resize(N);
    for (int i = 0; i < N; ++i)
    {
        outMatrix[i].resize(N);
    }

    // m1°ú m2 Çà·ÄÀÇ °ö
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                outMatrix[i][j] += (m1[i][k] * m2[k][j]);
            }
            outMatrix[i][j] %= MOD;
        }
    }

    return outMatrix;
}

vector<vector<long long>> solution(long long n)
{
    if (n == 1)
    {
        return matrix;
    }

    if (!cache[n].empty())
    {
        return cache[n];
    }

    // nÀÌ Â¦¼ö, È¦¼öÀÏ °æ¿ì ³ª´²¼­ ºÐÇÒ Á¤º¹
    if (n % 2 == 0)
    {
        cache[n] = mulMatrix(solution(n / 2), solution(n / 2));
        return cache[n];
    }
    else
    {
        cache[n] = mulMatrix(solution(n - 1), matrix);
        return cache[n];
    }
}

int main()
{
    cin >> N >> B;

    matrix.resize(N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int temp;
            cin >> temp;
            matrix[i].push_back(temp);
        }
    }

    cache[1] = matrix;

    vector<vector<long long>> answer = solution(B);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << answer[i][j] % MOD << " ";
        }
        cout << endl;
    }

    return 0;
}