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

int cache[501][501];
int triangle[501][501] = { -1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }

    /*for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << triangle[i][j] << " ";
        }
        cout << '\n';
    }*/

    cache[1][1] = triangle[1][1];
    cache[2][1] = triangle[1][1] + triangle[2][1];
    cache[2][2] = triangle[1][1] + triangle[2][2];

    for (int i = 3; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j == 1)
            {
                cache[i][j] = triangle[i][j] + cache[i - 1][j];
            }
            else if (j == N)
            {
                cache[i][j] = triangle[i][j] + cache[i - 1][j - 1];
            }
            else
            {
                cache[i][j] = triangle[i][j] + max(cache[i - 1][j - 1], cache[i - 1][j]);
            }
        }
    }

    /*for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << cache[i][j] << " ";
        }
        cout << '\n';
    }*/

    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        if (cache[N][i] > max)
        {
            max = cache[N][i];
        }
    }

    cout << max << '\n';

    return 0;
}