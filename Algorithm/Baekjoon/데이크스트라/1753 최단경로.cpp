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
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));
    while (!q.empty())
    {
        int now = q.top().second;
        int dis = -q.top().first;
        q.pop();
        if (d[now] < dis)continue;

        for (int i = 0; i < atob[now].size(); i++)
        {
            int next = atob[now][i].second;
            int NextDistance = dis + atob[now][i].first;
            if (NextDistance < d[next])
            {
                d[next] = NextDistance;
                q.push(make_pair(-NextDistance, next));
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    atob.resize(n);
    d.resize(n, INF);

    int k;
    cin >> k;

    for (int i = 0; i < m; i++)
    {
        int n1, n2, l;
        cin >> n1 >> n2 >> l;
        n1--;
        n2--;
        atob[n1].push_back(make_pair(l, n2));
    }

    dijkstra(k - 1);

    for (int i = 0; i < n; i++)
    {
        if (i == k - 1)
        {
            cout << "0" << '\n';
            continue;
        }
        if (d[i] == INF)
        {
            cout << "INF" << '\n';
            continue;
        }
        cout << d[i] << '\n';
    }
}