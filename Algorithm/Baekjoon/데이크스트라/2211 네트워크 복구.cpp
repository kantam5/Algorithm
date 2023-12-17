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
int parent[1001];

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

                // next_node를 최단 경로로 도달하기 위해서는 반드시 current_node에서부터 도달한다. 
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

    int N, M;
    cin >> N >> M;

    edges.resize(N + 1);
    dist.resize(N + 1, INT_MAX);

    for (int i = 0; i < M; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;

        edges[A].push_back(make_pair(C, B));
        edges[B].push_back(make_pair(C, A));
    }

    dijkstra(1);

    // 노드를 모두 연결해야 하므로 간선의 수는 N - 1개이다. 
    cout << N - 1 << '\n';
    // 2번 노드부터 자신과 부모 노드를 출력한다. 
    for (int i = 2; i <= N; ++i)
    {
        cout << i << " " << parent[i] << '\n';
    }

    return 0;
}
