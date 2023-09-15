#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

queue<int> q;
bool visited[101];
int edge_count = 0;
int _distance[101];
void bfs(const vector<int> _graph[], int source)    // source는 시작 노드
{
    // source 방문
    q.push(source);
    visited[source] = true;
    _distance[source] = 0;

    while (!q.empty())
    {

        int current = q.front();
        q.pop();

        // cout << "source: " << source << "  current: " << current << "  _distance[current]: " << _distance[current] << endl;

        for (int next : _graph[current])
        {
            if (!visited[next])
            {
                edge_count++;
                q.push(next);
                visited[next] = true;
                _distance[next] = _distance[current] + 1;
            }
        }
    }
}

int main()
{
    int N;
    int M;
    cin >> N >> M;

    vector<int> graph[101];
    for (int i = 0; i < M; i++)
    {
        int temp1;
        int temp2;
        cin >> temp1 >> temp2;

        // 무방향 그래프
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    int bacon[101];
    memset(bacon, 0, sizeof(bacon));
    for (int i = 1; i <= N; i++)
    {
        bfs(graph, i);
        for (int j = 1; j <= N; j++)
        {
            bacon[i] += _distance[j];
        }

        memset(visited, 0, sizeof(visited));
        memset(_distance, 0, sizeof(_distance));
        edge_count = 0;
    }

    int mini = 2147483647;
    for (int i = 1; i <= N; i++)
    {
        if (mini > bacon[i])
        {
            mini = bacon[i];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (mini == bacon[i])
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
