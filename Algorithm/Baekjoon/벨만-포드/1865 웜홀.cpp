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
int portal;

struct _edge
{
    int s;
    int e;
    int t;
};

bool bellman_ford(int n, vector<_edge> edges)
{
    vector<int> dist(n + 1, INF);

    int s, e, t;
    dist[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            s = edges[j].s;
            e = edges[j].e;
            t = edges[j].t;

            if (dist[e] > dist[s] + t)
                dist[e] = dist[s] + t;
        }
    }

    for (int j = 0; j < edges.size(); j++)
    {
        s = edges[j].s;
        e = edges[j].e;
        t = edges[j].t;

        if (dist[e] > dist[s] + t)
            return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int s, e, t;

    while (T--)
    {
        cin >> vertex >> edge >> portal;

        vector<_edge> edges;

        for (int i = 0; i < edge; i++)
        {
            cin >> s >> e >> t;
            edges.push_back({ s, e, t });
            edges.push_back({ e, s, t });
        }
        for (int i = 0; i < portal; i++)
        {
            cin >> s >> e >> t;
            edges.push_back({ s, e, -t });
        }

        if (bellman_ford(vertex, edges))
            cout << "YES\n";
        else
            cout << "NO\n";

    }
}