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

vector<int> graph[100001];
int parent[100001];

queue<int> q;
bool bfs_visited[100001];
void bfs(int source)
{
    q.push(source);
    bfs_visited[source] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        // cout << "source: " << source << "  current: " << current << '\n';

        for (int next : graph[current])
        {
            if (!bfs_visited[next])
            {
                q.push(next);
                bfs_visited[next] = true;
                parent[next] = current;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i < N; i++)
    {
        int v1;
        int v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    bfs(1);
    // dfs(1);

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << '\n';
    }

    return 0;
}