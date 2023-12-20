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
vector<vector<int>> path;       // path[node]는 최단 경로에서 node의 부모 노드의 벡터이다.
bool min_path[500][500];

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

            // 현재 경로가 최단 경로에 포함된다면 넘긴다.
            if (min_path[current_node][next_node])
            {
                continue;
            }

            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pq.push(make_pair((-1) * next_dist, next_node));

                // next_node까지의 최단 경로가 갱신되었으므로 path[next_node]를 새로 만든다.
                path[next_node].clear();
                path[next_node].push_back(current_node);
            }
            else if (next_dist == dist[next_node])
            {
                // next_node까지의 최단 경로가 여러개 있다는 뜻으로, path[next_node]에 current_node를 추가한다.
                path[next_node].push_back(current_node);
            }
        }
    }
}

// current부터 시작하여 path를 거꾸로 돌아가며 최단 경로에 포함되는 경로를 표시한다.
void check_path(int current)
{
    for (auto next : path[current])
    {
        for (int i = 0; i < edges[next].size(); ++i)
        {
            if (edges[next][i].second == current && !min_path[next][current])
            {
                min_path[next][current] = true;
                check_path(next);
                break;
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
    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
        {
            break;
        }

        int S, D;
        cin >> S >> D;

        edges.clear();
        edges.resize(N);
        dist.clear();
        dist.resize(N, INT_MAX);
        path.clear();
        path.resize(N);
        memset(min_path, false, sizeof(min_path));

        for (int i = 0; i < M; ++i)
        {
            int U, V, P;
            cin >> U >> V >> P;

            edges[U].push_back(make_pair(P, V));
        }

        // 다익스트라를 한번 실시
        dijkstra(S);

        // 최단 경로에 포함되는 경로를 모두 표시
        check_path(D);

        // 최단 경로를 제외하고 다시 다익스트라 실시
        dist.clear();
        dist.resize(N, INT_MAX);
        dijkstra(S);

        int answer = dist[D];
        if (answer == INT_MAX)
        {
            cout << "-1" << '\n';
        }
        else
        {
            cout << answer << '\n';
        }
    }

    return 0;
}

