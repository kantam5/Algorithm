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

using namespace std;

#define INF 999999999

vector<vector<pair<int, int>>> atob;
vector<int>d;

void dijkstra(int start)
{
    d[start] = 0;
    priority_queue<pair<int, int>> q;                       // 우선순위 큐, 거리가 가장 짧은 것 우선으로 뱉기위해 거리에 -가 붙는다.
    q.push(make_pair(0, start));

    while (!q.empty())
    {
        int now = q.top().second;                           // 현재 비교할 노드 now
        int dis = -q.top().first;                           // now까지의 거리
        q.pop();

        // 갱신 안됨
        if (d[now] < dis)
        {
            continue;
        }

        // 현재 노드에 연결된 간선들에 대해 계산
        for (int i = 0; i < atob[now].size(); i++)
        {
            int next = atob[now][i].second;                 // 현재 노드에 연결된 노드 중 하나
            int NextDistance = dis + atob[now][i].first;    // 현재 노드를 경우해서 next에 도달했을 때의 거리
            if (NextDistance < d[next])                     // 갱신 가능
            {
                d[next] = NextDistance;                     // start에서 next까지의 거리 갱신
                q.push(make_pair(-NextDistance, next));     // 우선순위 큐에 갱신된 값을 집어넣어 다시 비교
            }
        }
    }

}

int main()
{
    int n, m;
    cin >> n >> m;
    atob.resize(n);
    d.resize(n, INF);

    for (int i = 0; i < m; i++)
    {
        int n1, n2, l;
        cin >> n1 >> n2 >> l;
        n1--;
        n2--;
        atob[n1].push_back(make_pair(l, n2));
    }

    int s, e;
    cin >> s >> e;
    dijkstra(s - 1);

    cout << d[e - 1];
}