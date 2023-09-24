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

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int current_node = pq.top().second;
        int current_dist = (-1) * pq.top().first;
        pq.pop();

        if (dists[start][current_node] < current_dist)
        {
            continue;
        }

        for (int i = 0; i < edges[current_node].size(); ++i)
        {
            int next_node = edges[current_node][i].second;
            int next_dist = current_dist + edges[current_node][i].first;

            if (dists[start][next_node] > next_dist)
            {
                dists[start][next_node] = next_dist;
                pq.push(make_pair((-1) * next_dist, next_node));
            }
        }
    }
}

int main()
{
    int N;
    int E;
    int v1;
    int v2;
    int answer;

    cin >> N >> E;

    edges.resize(N + 1);
    dists.resize(N + 1);
    for (int i = 0; i < dists.size(); ++i)
    {
        dists[i].resize(N + 1, INT_MAX);
    }

    while (E--)
    {
        int n1;
        int n2;
        int dist;
        cin >> n1 >> n2 >> dist;

        edges[n1].push_back(make_pair(dist, n2));
        edges[n2].push_back(make_pair(dist, n1));
    }

    cin >> v1 >> v2;

    dijkstra(1);
    dijkstra(v1);
    dijkstra(v2);

    // 경로가 없는 경우
    if (dists[1][v1] == INT_MAX || dists[v1][v2] == INT_MAX || dists[v2][N] == INT_MAX
        || dists[1][v2] == INT_MAX || dists[v2][v1] == INT_MAX || dists[v1][N] == INT_MAX)
    {
        cout << "-1";
    }
    else
    {
        // 1 -> v1 -> v2 -> N
        // 1 -> v2 -> v1 -> N
        // 2가지 경로 중 작은 값을 출력
        cout << min(dists[1][v1] + dists[v1][v2] + dists[v2][N], dists[1][v2] + dists[v2][v1] + dists[v1][N]);
    }

    return 0;
}