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
#include <climits>

using namespace std;

int n, m, r;
int graph[101][101];

void floydWarshall()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                if (graph[j][i] != INT_MAX && graph[i][k] != INT_MAX)
                {
                    graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> itemNum_node;
    int answer = 0;

    cin >> n >> m >> r;

    // 노드 당 아이템 수 입력
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        itemNum_node.push_back(temp);
    }

    // 그래프 입력
    fill(&graph[0][0], &graph[100][100], INT_MAX);
    while (r--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        cin >> graph[n1][n2];
        graph[n2][n1] = graph[n1][n2];
    }

    for (int i = 1; i <= n; ++i)
    {
        graph[i][i] = 0;
    }

    floydWarshall();

    for (int i = 1; i <= n; ++i)
    {
        int temp = 0;
        for (int j = 1; j <= n; ++j)
        {
            // 경로가 m이하라면 아이템 수 추가 가능
            if (graph[i][j] <= m)
            {
                temp += itemNum_node[j - 1];
            }
        }

        answer = max(answer, temp);
    }

    cout << answer;

    return 0;
}