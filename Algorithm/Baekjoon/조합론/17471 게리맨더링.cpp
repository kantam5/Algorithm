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

int N;
int population[11];
bool selected[11];
bool edge[11][11];
bool visited[11];
int answer = INT_MAX;

// group이 문제의 조건과 맞는지 확인
bool bfs(vector<int> group, bool state)
{
    memset(visited, false, sizeof(visited));
    visited[group[0]] = true;

    queue<int> q;
    q.push(group[0]);

    int count = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            // i는 current와 같은 state여야 한다.
            // i와 current는 이어져 있어야 한다.
            // 방문한 선거구는 다시 방문하지 않는다.
            if (selected[i] == state && edge[current][i] == true && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
                count++;
            }
        }
    }

    // 조건에 맞게 방문한 선거구의 수가 group의 수와 맞다면 모두 연결된 상태이다.
    if (group.size() == count)
    {
        return true;
    }

    return false;
}

// A와 B구역의 인구차를 계산
void calculate()
{
    int A = 0;
    int B = 0;

    for (int i = 1; i <= N; i++)
    {
        if (selected[i] == true)
        {
            A += population[i];
        }
        else
        {
            B += population[i];
        }
    }

    int result = abs(A - B);

    answer = min(answer, result);
}

// A와 B구역이 문제의 조건과 맞는지 확인
bool check()
{
    vector<int> A;
    vector<int> B;

    for (int i = 1; i <= N; i++)
    {
        if (selected[i] == true)
        {
            A.push_back(i);
        }
        else
        {
            B.push_back(i);
        }
    }

    if (A.size() == 0 || B.size() == 0)
    {
        return false;
    }

    // A와 B모두 조건을 만족해야 한다.
    if (bfs(A, true) != true)
    {
        return false;
    }
    if (bfs(B, false) != true)
    {
        return false;
    }

    return true;
}

void dfs(int x, int count)
{
    // 구역은 1개 이상의 선거구를 가진다.
    if (count >= 1)
    {
        if (check() == true)
        {
            calculate();
        }
    }

    for (int i = x; i <= N; i++)
    {
        if (selected[i] == true)
        {
            continue;
        }

        // i를 선택, 해제를 반복하면서 모든 경우의 수를 체크
        selected[i] = true;
        dfs(i, count + 1);
        selected[i] = false;
    }
}
int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> population[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int count;
        cin >> count;

        for (int j = 0; j < count; j++)
        {
            int dest;
            cin >> dest;

            edge[i][dest] = true;
            edge[dest][i] = true;
        }
    }

    dfs(1, 0);

    if (answer == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }

    return 0;
}
