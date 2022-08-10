#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

bool visited[100];

int result[101][101];

// current노드부터 시작하여 graph를 깊이 우선 탐색
void dfs(vector<int> graph[], int current, int n)
{
    if (current != n)
    {
        result[n][current] = 1;
    }

    visited[current] = true;

    for (int next : graph[current])
    {
        if (next == n && visited[next])
        {
            result[n][next] = 1;
        }
        if (!visited[next])
        {
            dfs(graph, next, n);
        }
    }
}

int main()
{
    int repeat;
    cin >> repeat;

    vector<int> graph[100];
    for (int i = 0; i < repeat; i++)
    {
        for (int j = 0; j < repeat; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                graph[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < repeat; i++)
    {
        dfs(graph, i, i);
        memset(visited, false, sizeof(visited));
    }

    for (int i = 0; i < repeat; i++)
    {
        for (int j = 0; j < repeat; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}