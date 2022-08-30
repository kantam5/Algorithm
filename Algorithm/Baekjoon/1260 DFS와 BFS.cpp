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

using namespace std;

queue<int> q;
bool bfs_visited[1001];
vector<int> bfs_arr;
void bfs(const vector<int> graph[], int source)
{
    q.push(source);
    bfs_visited[source] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        bfs_arr.push_back(current);
        // cout << "source: " << source << "  current: " << current << "  _distance[current]: " << _distance[current] << endl;

        for (int next : graph[current])
        {
            if (!bfs_visited[next])
            {
                q.push(next);
                bfs_visited[next] = true;
            }
        }
    }
}

bool dfs_visited[1001];
vector<int> dfs_arr;
void dfs(vector<int> graph[], int current, int n)
{
    dfs_visited[current] = true;
    dfs_arr.push_back(current);

    for (int next : graph[current])
    {
        if (!dfs_visited[next])
        {
            dfs(graph, next, n);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int M;
    int V;
    cin >> N >> M >> V;

    vector<int> graph[1001];
    for (int i = 0; i < M; i++)
    {
        int v1;
        int v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, V, V);
    bfs(graph, V);

    for (int i = 0; i < dfs_arr.size(); i++)
    {
        cout << dfs_arr[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < bfs_arr.size(); i++)
    {
        cout << bfs_arr[i] << " ";
    }
    cout << '\n';

    return 0;
}