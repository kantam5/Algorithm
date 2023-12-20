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
vector<vector<int>> path;       // path[node]�� �ִ� ��ο��� node�� �θ� ����� �����̴�.
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

            // ���� ��ΰ� �ִ� ��ο� ���Եȴٸ� �ѱ��.
            if (min_path[current_node][next_node])
            {
                continue;
            }

            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pq.push(make_pair((-1) * next_dist, next_node));

                // next_node������ �ִ� ��ΰ� ���ŵǾ����Ƿ� path[next_node]�� ���� �����.
                path[next_node].clear();
                path[next_node].push_back(current_node);
            }
            else if (next_dist == dist[next_node])
            {
                // next_node������ �ִ� ��ΰ� ������ �ִٴ� ������, path[next_node]�� current_node�� �߰��Ѵ�.
                path[next_node].push_back(current_node);
            }
        }
    }
}

// current���� �����Ͽ� path�� �Ųٷ� ���ư��� �ִ� ��ο� ���ԵǴ� ��θ� ǥ���Ѵ�.
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

        // ���ͽ�Ʈ�� �ѹ� �ǽ�
        dijkstra(S);

        // �ִ� ��ο� ���ԵǴ� ��θ� ��� ǥ��
        check_path(D);

        // �ִ� ��θ� �����ϰ� �ٽ� ���ͽ�Ʈ�� �ǽ�
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

