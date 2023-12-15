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
            int next_node = edge.second;
            int next_dist = edge.first + current_dist;
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

    int N, D;
    cin >> N >> D;

    edges.resize(D + 1);
    dist.resize(D + 1, INT_MAX);

    // 도로를 특정 노드가 다음 노드와 거리 1로 연결된 그래프라고 생각한다.
    for (int i = 0; i < D; ++i)
    {
        edges[i].push_back(make_pair(1, i + 1));
    }

    // 지름길을 추가한다.
    vector<int> starts;
    for (int i = 0; i < N; ++i)
    {
        int start, end, distance;
        cin >> start >> end >> distance;

        // 역주행 할 수는 없으므로 end가 D를 초과한 경우에는 edges에 넣지 않는다.
        // 거리를 줄일 수 없는 지름길은 edges에 넣지 않는다.
        if (end <= D && (end - start) > distance)
        {
            starts.push_back(start);
            edges[start].push_back(make_pair(distance, end));
        }
    }

    dijkstra(0);

    cout << dist[D];

    return 0;
}
