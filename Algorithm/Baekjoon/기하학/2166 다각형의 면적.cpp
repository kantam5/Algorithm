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

int main()
{
    int N;
    long double answer = 0;

    cin >> N;

    vector<pair<long long, long long>> coordinate;
    coordinate.resize(N);

    for (int i = 0; i < N; ++i)
    {
        long long x, y;
        cin >> x >> y;

        coordinate[i] = make_pair(x, y);
    }

    for (int i = 1; i <= N; ++i)
    {
        pair<long long, long long> bef = coordinate[i - 1];

        if (i == N)
        {
            answer += (bef.first * coordinate[0].second) - (bef.second * coordinate[0].first);
            break;
        }
        answer += (bef.first * coordinate[i].second) - (bef.second * coordinate[i].first);
    }

    if (answer < 0)
    {
        answer *= -1;
    }
    answer /= 2;
    answer *= 10;
    answer = round(answer);
    answer /= 10;
    printf("%.1Lf", answer);

    return 0;
}