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

vector<vector<pair<int, int>>> edges;
vector<int> dist;
int parent[201];

void dijkstra(int start)
{
    dist[start] = 0;
    parent[start] = start;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int current_node = pq.top().second;
        int current_dist = (-1) * pq.top().first;
        pq.pop();

        if (dist[current_node] < current_dist)
        {
            continue;
        }

        for (auto edge : edges[current_node])
        {
            int next_node = edge.second;
            int next_dist = edge.first + current_dist;
            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pq.push(make_pair((-1) * next_dist, next_node));

                // �ִܰ�ΰ� ���ŵ� ��, next_node�� �θ� ��带 current_node�� ����
                parent[next_node] = current_node;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    edges.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int start, end, distance;
        cin >> start >> end >> distance;

        edges[start].push_back(make_pair(distance, end));
        edges[end].push_back(make_pair(distance, start));
    }

    // �� �����忡�� ���ͽ�Ʈ�� ����
    for (int i = 1; i <= n; ++i)
    {
        dist.clear();
        dist.resize(n + 1, INT_MAX);
        memset(parent, 0, sizeof(parent));

        dijkstra(i);

        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                cout << "- ";
                continue;
            }

            // �������� �θ��尡 i�� �ƴ� ������ �ö󰣴�.
            // �׷��� �Ǹ�, i -> j�� ��ο��� i �ٷ� ���� ��尡 current_parent�� �ȴ�.
            int current_parent = j;
            while (parent[current_parent] != i)
            {
                current_parent = parent[current_parent];
            }
            cout << current_parent << " ";
        }
        cout << '\n';

    }

    return 0;
}
