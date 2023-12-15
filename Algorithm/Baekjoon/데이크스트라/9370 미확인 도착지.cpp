#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> edges;
vector<vector<int>> dist;

void dijkstra(int start)
{
    dist[start][start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int current_node = pq.top().second;
        int current_dist = (-1) * pq.top().first;
        pq.pop();

        if (dist[start][current_node] < current_dist)
        {
            continue;
        }

        for (auto edge : edges[current_node])
        {
            int next_node = edge.second;
            int next_dist = edge.first + current_dist;
            if (next_dist < dist[start][next_node])
            {
                dist[start][next_node] = next_dist;
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

    int T;
    cin >> T;

    while (T--)
    {
        int n, m, t;
        cin >> n >> m >> t;
        int s, g, h;
        cin >> s >> g >> h;

        edges.resize(n + 1);
        dist.resize(n + 1);
        for (int i = 0; i < dist.size(); ++i)
        {
            dist[i].resize(n + 1, INT_MAX);
        }

        for (int i = 0; i < m; ++i)
        {
            int a, b, d;
            cin >> a >> b >> d;
            edges[a].push_back(make_pair(d, b));
            edges[b].push_back(make_pair(d, a));
        }

        // s, g, h를 시작점으로 세 번 다익스트라를 실시
        dijkstra(s);
        dijkstra(g);
        dijkstra(h);

        vector<int> answer;
        for (int i = 0; i < t; ++i)
        {
            int x;
            cin >> x;

            // s -> g -> h -> x 로 가는 경로의 비용이 s -> x 로 가는 최소 경로의 비용이 일치한다면 answer에 추가
            if (dist[s][g] + dist[g][h] + dist[h][x] == dist[s][x])
            {
                answer.push_back(x);
            }
            // s -> h -> g -> x 로 가는 경로의 비용이 s -> x 로 가는 최소 경로의 비용이 일치한다면 answer에 추가
            else if (dist[s][h] + dist[h][g] + dist[g][x] == dist[s][x])
            {
                answer.push_back(x);
            }
        }

        sort(answer.begin(), answer.end());
        for (int i = 0; i < answer.size(); ++i)
        {
            cout << answer[i] << " ";
        }
        cout << '\n';

        edges.clear();
        dist.clear();
    }

    return 0;
}