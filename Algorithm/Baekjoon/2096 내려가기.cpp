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

int maxCache[3];
int minCache[3];
int tempCache[3];
int paper[100001][3];   // 3개로 줄여도 가능

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> paper[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            maxCache[0] = paper[0][0];
            maxCache[1] = paper[0][1];
            maxCache[2] = paper[0][2];

            minCache[0] = paper[0][0];
            minCache[1] = paper[0][1];
            minCache[2] = paper[0][2];
            continue;
        }

        tempCache[0] = maxCache[0];
        tempCache[1] = maxCache[1];
        tempCache[2] = maxCache[2];

        maxCache[0] = max(tempCache[0] + paper[i][0], tempCache[1] + paper[i][0]);
        maxCache[1] = max(max(tempCache[0] + paper[i][1], tempCache[1] + paper[i][1]), tempCache[2] + paper[i][1]);
        maxCache[2] = max(tempCache[1] + paper[i][2], tempCache[2] + paper[i][2]);

        tempCache[0] = minCache[0];
        tempCache[1] = minCache[1];
        tempCache[2] = minCache[2];

        minCache[0] = min(tempCache[0] + paper[i][0], tempCache[1] + paper[i][0]);
        minCache[1] = min(min(tempCache[0] + paper[i][1], tempCache[1] + paper[i][1]), tempCache[2] + paper[i][1]);
        minCache[2] = min(tempCache[1] + paper[i][2], tempCache[2] + paper[i][2]);
    }

    cout << max(max(maxCache[0], maxCache[1]), maxCache[2]) << " " << min(min(minCache[0], minCache[1]), minCache[2]);

    return 0;
}