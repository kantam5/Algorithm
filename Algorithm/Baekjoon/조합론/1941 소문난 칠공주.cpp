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
#include <sstream>
#include <cstdlib>

using namespace std;

char room[5][5];
bool selected[5][5];
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> answer;
int answer_count = 0;

// 선택한 자리가 모두 상하좌우로 연결되어 있는지 확인
bool checkLinked()
{
    bool visited[5][5];
    memset(visited, false, sizeof(visited));

    int count = 0;

    pair<int, int> start = answer[0];
    visited[start.first][start.second] = true;

    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        count++;

        for (int i = 0; i < 4; ++i)
        {
            int next_x = current.first + move_x[i];
            int next_y = current.second + move_y[i];

            if (next_x < 0 || next_x >= 5 || next_y < 0 || next_y >= 5 || visited[next_x][next_y])
            {
                continue;
            }

            if (selected[next_x][next_y])
            {
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x, next_y));
            }
        }
    }

    // 방문한 자리의 수가 7이라면 모두 연결되어 있다.
    return count == 7;
}

// 선택한 자리의 S의 수가 4이상인지 확인
bool isMoreThanFour()
{
    int count = 0;

    for (int i = 0; i < answer.size(); ++i)
    {
        if (room[answer[i].first][answer[i].second] == 'S')
        {
            count++;
        }
    }

    return count >= 4;
}

void dfs(int current)
{
    // 7개의 자리를 선택했다면 문제의 조건을 만족하는지 확인
    if (answer.size() == 7)
    {
        if (checkLinked() && isMoreThanFour())
        {
            answer_count++;
        }

        return;
    }

    for (int i = current; i < 25; ++i)
    {
        int current_x = i / 5;
        int current_y = i % 5;

        answer.push_back(make_pair(current_x, current_y));
        selected[current_x][current_y] = true;

        dfs(i + 1);

        answer.pop_back();
        selected[current_x][current_y] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> room[i][j];
        }
    }

    dfs(0);

    cout << answer_count;

    return 0;
}
