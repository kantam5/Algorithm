#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int edge_count = 0;

bool visited[1001];
// current노드부터 시작하여 graph를 깊이 우선 탐색
void dfs(vector<int> _graph[], int current, int n)
{
    edge_count++;
    visited[current] = true;

    for (int next : _graph[current])
    {
        if (!visited[next])
        {
            dfs(_graph, next, n);
        }
    }
}

int main()
{
    int N;
    int M;
    cin >> N >> M;

    vector<int> graph[1001];
    for (int i = 0; i < M; i++)
    {
        int temp1;
        int temp2;
        cin >> temp1 >> temp2;

        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    /*if (M == 0 || N == 1)
    {
        cout << N << endl;
        return 0;
    }*/

    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            dfs(graph, i, i);
            result++;
        }
        /*if (edge_count > 1)
        {
            result++;
        }

        edge_count = 0;*/
    }

    cout << result << endl;

    return 0;
}