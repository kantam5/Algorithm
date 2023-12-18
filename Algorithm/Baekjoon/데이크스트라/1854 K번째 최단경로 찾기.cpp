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

int k;
vector<vector<pair<int, int>>> edges;
vector<priority_queue<int>> dist_pq;        // 정점까지의 거리를 저장

void dijkstra(int start)
{
    // start에서 start는 0
    dist_pq[start].push(0);

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int current_node = pq.top().second;
        int current_dist = (-1) * pq.top().first;
        pq.pop();

        for (auto edge : edges[current_node])
        {
            int next_node = edge.second;
            int next_dist = edge.first + current_dist;

            // next_node까지의 거리를 아직 덜 구해놓았다면 dist_pq에 추가한다.
            // 다익스트라를 추가로 진행하기 위해 pq에도 추가한다.
            if (dist_pq[next_node].size() < k)
            {
                dist_pq[next_node].push(next_dist);

                pq.push(make_pair((-1) * next_dist, next_node));
            }
            else
            {
                // next_node까지의 거리를 이미 k이상 구해놓았다면 현재 가장 높은 비용(top)과 next_dist를 비교하여
                // next_dist가 더 작을 경우에 top을 빼고 next_dist를 추가한다.
                // 다익스트라를 추가로 진행하기 위해 pq에도 추가한다.
                if (dist_pq[next_node].top() > next_dist)
                {
                    dist_pq[next_node].pop();
                    dist_pq[next_node].push(next_dist);

                    pq.push(make_pair((-1) * next_dist, next_node));
                }
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
    cin >> n >> m >> k;

    edges.resize(n + 1);
    dist_pq.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back(make_pair(c, b));
    }

    dijkstra(1);

    for (int i = 1; i <= n; ++i)
    {
        if (dist_pq[i].size() < k)
        {
            cout << "-1" << '\n';
        }
        else
        {
            // dist_pq[i].top()이 i 노드까지의 k번째 비용
            cout << dist_pq[i].top() << '\n';
        }
    }

    return 0;
}
