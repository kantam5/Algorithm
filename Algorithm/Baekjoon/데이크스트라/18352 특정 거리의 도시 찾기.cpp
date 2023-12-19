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

vector<vector<int>> edges;
vector<int> dist;

void dijkstra(int start)
{
    dist[start] = 0;

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
            int next_node = edge;
            int next_dist = current_dist + 1;
            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pq.push(make_pair((-1) * next_dist, next_node));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    edges.resize(N + 1);
    dist.resize(N + 1, INT_MAX);

    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        edges[A].push_back(B);
    }

    dijkstra(X);

    bool flag = false;
    for (int i = 1; i <= N; ++i)
    {
        if (dist[i] == K)
        {
            flag = true;
            cout << i << '\n';
        }
    }

    if (!flag)
    {
        cout << "-1" << '\n';
    }

    return 0;
}
