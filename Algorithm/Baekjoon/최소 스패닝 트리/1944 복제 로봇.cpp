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
    int n1;
    int n2;
    int dist;
}edge;

vector<edge> edges;
int parent[251];

int N, M;
char maze[51][51];
int nums[51][51];

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

// bfs로 각 칸 사이의 거리를 찾는다.
void bfs(int x, int y)
{
    bool visited[51][51];
    memset(visited, false, sizeof(visited));
    int move_x[4] = { 0, 0, -1, 1 };
    int move_y[4] = { 1, -1, 0, 0 };

    // queue의 데이터는 현재 칸의 좌표와 현재까지의 거리를 가진다.
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(x, y), 0));
    visited[x][y] = true;

    while (!q.empty())
    {
        int current_x = q.front().first.first;
        int current_y = q.front().first.second;
        int current_dist = q.front().second;
        q.pop();

        // 현재 칸이 시작칸이 아니면서 K혹은 S라면 간선으로 저장한다.
        if (maze[current_x][current_y] == 'K' || maze[current_x][current_y] == 'S')
        {
            if (!(current_x == x && current_y == y))
            {
                int current_node = nums[x][y];
                int next_node = nums[current_x][current_y];
                edges.push_back({ current_node, next_node, current_dist });
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            int next_x = current_x + move_x[i];
            int next_y = current_y + move_y[i];
            int next_dist = current_dist + 1;

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || visited[next_x][next_y])
            {
                continue;
            }

            if (maze[next_x][next_y] != '1')
            {
                q.push(make_pair(make_pair(next_x, next_y), next_dist));
                visited[next_x][next_y] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int node_count = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> maze[i][j];

            if (maze[i][j] == 'S' || maze[i][j] == 'K')
            {
                nums[i][j] = node_count;
                node_count++;
            }
        }
    }

    // 로봇을 복제할 수 있는 S, K 사이를 간선으로 설정한다.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (maze[i][j] == 'S' || maze[i][j] == 'K')
            {
                bfs(i, j);
            }
        }
    }

    // 크루스칼 알고리즘 실시
    for (int i = 0; i < M + 1; ++i)
    {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), compare);

    int answer = 0;
    int edge_count = 0;
    for (auto edge : edges)
    {
        if (!cycle(edge.n1, edge.n2))
        {
            Union(edge.n1, edge.n2);
            answer += edge.dist;
            edge_count++;
        }
    }

    if (edge_count < M)
    {
        cout << "-1";
    }
    else
    {
        cout << answer;
    }

    return 0;
}
