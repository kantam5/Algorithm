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
vector<priority_queue<int>> dist_pq;        // ���������� �Ÿ��� ����

void dijkstra(int start)
{
    // start���� start�� 0
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

            // next_node������ �Ÿ��� ���� �� ���س��Ҵٸ� dist_pq�� �߰��Ѵ�.
            // ���ͽ�Ʈ�� �߰��� �����ϱ� ���� pq���� �߰��Ѵ�.
            if (dist_pq[next_node].size() < k)
            {
                dist_pq[next_node].push(next_dist);

                pq.push(make_pair((-1) * next_dist, next_node));
            }
            else
            {
                // next_node������ �Ÿ��� �̹� k�̻� ���س��Ҵٸ� ���� ���� ���� ���(top)�� next_dist�� ���Ͽ�
                // next_dist�� �� ���� ��쿡 top�� ���� next_dist�� �߰��Ѵ�.
                // ���ͽ�Ʈ�� �߰��� �����ϱ� ���� pq���� �߰��Ѵ�.
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
            // dist_pq[i].top()�� i �������� k��° ���
            cout << dist_pq[i].top() << '\n';
        }
    }

    return 0;
}
