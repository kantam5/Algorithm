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

int n, m;
int start_node, end_node;
vector<vector<pair<int, int>>> graph;
int dist[1001][1001];
int parent[1001];
vector<int> path;

void dijkstra(int n)
{
    dist[n][n] = 0;
    parent[n] = n;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, n));

    while (!pq.empty())
    {
        int current_node = pq.top().second;
        int current_dist = (-1) * pq.top().first;
        pq.pop();

        if (current_dist > dist[n][current_node])
        {
            continue;
        }

        for (auto next : graph[current_node])
        {
            int next_node = next.second;
            int next_dist = next.first + current_dist;

            // ��� ����
            if (dist[n][next_node] > next_dist)
            {
                dist[n][next_node] = next_dist;
                pq.push(make_pair((-1) * next_dist, next_node));

                // �ּҺ������ next_node�� �����ϱ� ���ؼ� current_node�� �ٷ� ������ ������ �Ѵ�.
                parent[next_node] = current_node;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    fill(&dist[0][0], &dist[1000][1001], INT_MAX);

    graph.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        graph[i].resize(n + 1);
    }

    while (m--)
    {
        int n1, n2, dist;
        cin >> n1 >> n2 >> dist;

        graph[n1].push_back(make_pair(dist, n2));
    }

    cin >> start_node >> end_node;

    dijkstra(start_node);

    cout << dist[start_node][end_node] << endl;

    // ��� ����
    // ���� ����� �θ� ��带 �����ϸ鼭 �θ� ��尡 start_node�� ��� ����
    int current_parent = end_node;
    while (current_parent != start_node)
    {
        path.push_back(current_parent);
        current_parent = parent[current_parent];
    }
    path.push_back(start_node);             // ���� ��� push

    cout << path.size() << endl;

    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[path.size() - 1 - i] << " ";
    }

    return 0;
}