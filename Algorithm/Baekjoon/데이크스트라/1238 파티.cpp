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

vector<vector<pair<int, int>>> edges;
vector<vector<int>> dists;

void dijkstra(int start)
{
    dists[start][start] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));

    while (!q.empty())
    {
        int current_node = q.top().second;
        int current_dist = -q.top().first;
        q.pop();

        if (dists[start][current_node] < current_dist)
        {
            continue;
        }

        for (int i = 0; i < edges[current_node].size(); ++i)
        {
            int next_node = edges[current_node][i].second;
            int next_dist = current_dist + edges[current_node][i].first;
            if (next_dist < dists[start][next_node])
            {
                dists[start][next_node] = next_dist;
                q.push(make_pair((-1) * next_dist, next_node));
            }
        }
    }
}


int main()
{
    // N명의 학생, M명의 다리, X번 마을에 모인다.
    int N, M, X;
    int answer = 0;

    cin >> N >> M >> X;

    edges.resize(N);

    dists.resize(N);
    for (int i = 0; i < N; ++i)
    {
        dists[i].resize(N, INT_MAX);
    }

    for (int i = 0; i < M; ++i)
    {
        int n1, n2, dist;
        cin >> n1 >> n2 >> dist;

        edges[n1 - 1].push_back(make_pair(dist, n2 - 1));
    }

    for (int i = 0; i < N; ++i)
    {
        dijkstra(i);
    }

    for (int i = 0; i < N; ++i)
    {
        answer = max(answer, dists[i][X - 1] + dists[X - 1][i]);
    }

    cout << answer;

    return 0;
}


// 역방향을 활용하면 다익스트라 2번만에 정답을 구할 수 있다. 
// X까지걸리는 시간의 최대값을 구할 수 있다.
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

vector<vector<pair<int, int>>> edges;
vector<vector<pair<int, int>>> reverse_edges;
vector<vector<int>> dists;
vector<vector<int>> reverse_dists;

void dijkstra(int start)
{
    dists[start][start] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));

    while (!q.empty())
    {
        int current_node = q.top().second;
        int current_dist = -q.top().first;
        q.pop();

        if (dists[start][current_node] < current_dist)
        {
            continue;
        }

        for (int i = 0; i < edges[current_node].size(); ++i)
        {
            int next_node = edges[current_node][i].second;
            int next_dist = current_dist + edges[current_node][i].first;
            if (next_dist < dists[start][next_node])
            {
                dists[start][next_node] = next_dist;
                q.push(make_pair((-1) * next_dist, next_node));
            }
        }
    }
}

void reverse_dijkstra(int start)
{
    reverse_dists[start][start] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));

    while (!q.empty())
    {
        int current_node = q.top().second;
        int current_dist = (-1) * q.top().first;
        q.pop();

        if (reverse_dists[start][current_node] < current_dist)
        {
            continue;
        }

        for (int i = 0; i < reverse_edges[current_node].size(); ++i)
        {
            int next_node = reverse_edges[current_node][i].second;
            int next_dist = current_dist + reverse_edges[current_node][i].first;
            if (next_dist < reverse_dists[start][next_node])
            {
                reverse_dists[start][next_node] = next_dist;
                q.push(make_pair((-1) * next_dist, next_node));
            }
        }
    }
}

int main()
{
    // N명의 학생, M명의 다리, X번 마을에 모인다.
    int N, M, X;
    int answer = 0;

    cin >> N >> M >> X;

    edges.resize(N);
    dists.resize(N);
    for (int i = 0; i < N; ++i)
    {
        dists[i].resize(N, INT_MAX);
    }

    reverse_edges.resize(N);
    reverse_dists.resize(N);
    for (int i = 0; i < N; ++i)
    {
        reverse_dists[i].resize(N, INT_MAX);
    }

    for (int i = 0; i < M; ++i)
    {
        int n1, n2, dist;
        cin >> n1 >> n2 >> dist;

        edges[n1 - 1].push_back(make_pair(dist, n2 - 1));
        reverse_edges[n2 - 1].push_back(make_pair(dist, n1 - 1));
    }

    // N명 만큼 다익스트라 계산
    /*for (int i = 0; i < N; ++i)
    {
        dijkstra(i);
    }
    for (int i = 0; i < N; ++i)
    {
        answer = max(answer, dists[i][X - 1] + dists[X - 1][i]);
    }*/

    dijkstra(X - 1);
    reverse_dijkstra(X - 1);

    for (int i = 0; i < N; ++i)
    {
        answer = max(answer, dists[X - 1][i] + reverse_dists[X - 1][i]);
    }

    cout << answer;

    return 0;
}