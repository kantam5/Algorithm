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

vector<pair<int, int>> graph[100001];
int maxi;

int deepest_v;

bool dfs_visited[100001];
vector<int> dfs_arr;
void dfs(vector<pair<int, int>> graph[], int current, int n, int value)
{
    if (maxi < value)
    {
        maxi = value;
        deepest_v = current;
    }

    dfs_visited[current] = true;
    dfs_arr.push_back(current);

    // cout << "source: " << n << "  current: " << current << "  value: " << value << '\n';

    for (pair<int, int> next : graph[current])
    {
        if (!dfs_visited[next.first])
        {
            dfs(graph, next.first, n, value + next.second);
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

    int v1, v2, e;
    for (int i = 1; i < N; i++)
    {
        cin >> v1;
        while (true)
        {
            cin >> v2;
            if (v2 == -1)
                break;

            cin >> e;

            graph[v2].push_back(make_pair(v1, e));
            graph[v1].push_back(make_pair(v2, e));
        }
    }

    dfs(graph, 1, 1, 0);
    memset(dfs_visited, false, sizeof(dfs_visited));
    dfs_arr.clear();
    maxi = 0;

    dfs(graph, deepest_v, deepest_v, 0);

    cout << maxi << '\n';

    return 0;
}