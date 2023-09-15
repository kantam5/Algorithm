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

int vertex;
int edge;
int arr[101][101];

void floyd_warshall()
{
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            for (int k = 0; k < vertex; k++)
            {
                if (arr[j][i] != INF && arr[i][k] != INF)
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
}

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

    cin >> vertex >> edge;

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            arr[i][j] = INF;
        }
    }

    for (int i = 0; i < edge; i++)
    {
        int n1, n2, l;
        cin >> n1 >> n2 >> l;
        n1--;
        n2--;

        arr[n1][n2] = min(arr[n1][n2], l);
    }

    floyd_warshall();

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            if (i == j || arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    /*int n, m;
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

    for (int i = 0; i < n; i++)
    {
        dijkstra(i);

        for (int j = 0; j < n; j++)
        {
            if (j == i || d[j] == INF)
            {
                cout << "0 ";
                continue;
            }
            cout << d[j] << " ";
        }

        d.assign(n, INF);
        cout << '\n';
    }*/


}