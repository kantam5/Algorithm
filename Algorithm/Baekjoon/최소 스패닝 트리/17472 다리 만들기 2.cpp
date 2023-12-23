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

typedef struct
{
    int v1;
    int v2;
    int dist;
}edge;
vector<edge> edges;
int parent[6];

int N, M;
int nums[10][10];
bool visited[10][10];

int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };

int island[10][10];

void bfs(int x, int y, int island_count)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    island[x][y] = island_count;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int next_x = current.first + move_x[i];
            int next_y = current.second + move_y[i];
            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M || visited[next_x][next_y])
            {
                continue;
            }

            // (x, y)와 연결된 땅을 island_count로 표시하여 섬으로 표시한다.
            if (nums[next_x][next_y] == 1)
            {
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x, next_y));

                island[next_x][next_y] = island_count;
            }
        }
    }
}

bool compare(edge a, edge b)
{
    return a.dist < b.dist;
}

int getParent(int n)
{
    if (n == parent[n])
    {
        return n;
    }
    return getParent(parent[n]);
}

bool cycle(int n1, int n2)
{
    n1 = getParent(n1);
    n2 = getParent(n2);
    return n1 == n2;
}

void Union(int n1, int n2)
{
    int p1 = getParent(n1);
    int p2 = getParent(n2);
    if (p1 < p2)
    {
        parent[p2] = p1;
    }
    else
    {
        parent[p1] = p2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> nums[i][j];
        }
    }

    // bfs로 2차원 배열에 섬을 표시한다.
    memset(island, -1, sizeof(island));
    int island_count = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (nums[i][j] == 1 && !visited[i][j])
            {
                bfs(i, j, island_count);
                island_count++;
            }
        }
    }

    // 모든 점에 상하좌우로 움직이면서 다른 섬을 만나면 간선으로 vector에 넣는다.
    for (int x = 0; x < N; ++x)
    {
        for (int y = 0; y < M; ++y)
        {
            if (island[x][y] == -1)
            {
                continue;
            }

            int current_island = island[x][y];

            for (int dir = 0; dir < 4; ++dir)
            {
                int next_x = x;
                int next_y = y;
                while (true)
                {
                    next_x += move_x[dir];
                    next_y += move_y[dir];
                    int next_island = island[next_x][next_y];

                    // 상하좌우로 움직였을 때, 범위를 초과했거나 시작 섬과 같은 섬이라면 break;
                    if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M || next_island == current_island)
                    {
                        break;
                    }

                    // 움직였을 때, 빈공간이라면 다음 칸으로 움직인다.
                    if (next_island == -1)
                    {
                        continue;
                    }

                    // 다른 섬일 경우 거리는 x의 차 혹은 y의 차이다.
                    int dist = abs((x - next_x) + (y - next_y)) - 1;
                    if (dist >= 2)
                    {
                        edges.push_back({ current_island, next_island, dist });
                    }
                    break;
                }
            }
        }
    }

    // 크루스칼 알고리즘 실시
    for (int i = 0; i < 6; ++i)
    {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), compare);

    int answer = 0;
    int edge_count = 0;
    for (auto edge : edges)
    {
        if (!cycle(edge.v1, edge.v2))
        {
            answer += edge.dist;
            edge_count++;
            Union(edge.v1, edge.v2);
        }
    }

    // 연결한 간선의 수가 (섬의 수 - 1)보다 작다면 모든 섬이 연결되지 않았으므로 -1 출력
    if (edge_count < island_count - 1)
    {
        cout << "-1";
    }
    else
    {
        cout << answer;
    }

    return 0;
}

