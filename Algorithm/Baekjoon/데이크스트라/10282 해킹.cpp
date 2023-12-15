#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> edges;
vector<int> dist;

void solution(int start)
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
            int next_dist = current_dist + edge.first;

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

    int T;
    cin >> T;

    while (T--)
    {
        int n, d, c;
        cin >> n >> d >> c;

        edges.resize(n + 1);
        dist.resize(n + 1, INT_MAX);

        for (int i = 0; i < d; ++i)
        {
            int a, b, s;
            cin >> a >> b >> s;

            // b�� �����ǰ� s�� ��, a�� �����ǹǷ� 
            // b���� a�� ����� s�� ����
            edges[b].push_back(make_pair(s, a));
        }

        solution(c);

        int count = 0;
        int max_time = 0;
        for (int i = 1; i < n + 1; ++i)
        {
            // c���� �� �� �ִ� ��ǻ���� ����
            // �ִ� �Ÿ��� ���Ѵ�.
            if (dist[i] != INT_MAX)
            {
                count++;
                max_time = max(max_time, dist[i]);
            }
        }
        edges.clear();
        dist.clear();

        cout << count << " " << max_time << '\n';

    }

    return 0;
}