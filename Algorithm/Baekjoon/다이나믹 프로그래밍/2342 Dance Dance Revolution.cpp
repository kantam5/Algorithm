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

vector<int> move_node;
//vector<vector<pair<int, pair<int, int>>>> cache;
int cache[100'001][5][5];

int dist(int from, int to)
{
    if (from == 0)
    {
        return 2;
    }
    else if (from == to)
    {
        return 1;
    }
    else if (abs(from - to) == 2)
    {
        return 4;
    }
    else
    {
        return 3;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int temp = -1;
    move_node.push_back(0);
    while (temp != 0)
    {
        cin >> temp;
        if (temp != 0)
        {
            move_node.push_back(temp);
        }
    }

    // 첫 위치인 0단계에서 0, 0의 위치는 0으로 두고 나머지는 INT_MAX로 초기화
    fill(&cache[0][0][0], &cache[100'000][4][5], INT_MAX);
    cache[0][0][0] = 0;

    for (int i = 1; i < move_node.size(); ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            for (int k = 0; k < 5; ++k)
            {
                // i - 1의 단계에서 INT_MAX라는 의미는 해당 단계의 발의 위치에 있는 건 불가능하다는 의미
                if (cache[i - 1][j][k] == INT_MAX)
                {
                    continue;
                }

                // i - 1단계에서 존재 가능한 발의 위치에서
                // 현재 움직이려는 위치로 왼발 혹은 오른발을
                // 움직였을 때 생기는 모든 경우를 담는다.
                cache[i][move_node[i]][k] = min(cache[i][move_node[i]][k],
                    cache[i - 1][j][k] + dist(j, move_node[i]));

                cache[i][j][move_node[i]] = min(cache[i][j][move_node[i]],
                    cache[i - 1][j][k] + dist(k, move_node[i]));
            }
        }
    }

    // 마지막 단계에서 최솟값을 찾는다.
    int answer = INT_MAX;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            answer = min(answer, cache[move_node.size() - 1][i][j]);
        }
    }

    cout << answer;

    return 0;
}