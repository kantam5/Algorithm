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

int N;
int M;
bool visited[9];
vector<int> arr;
void dfs(const vector<int> graph[], int current, int source, int distance)
{
    if (M == distance)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';

        return;
    }

    for (int next : graph[current])
    {
        arr.push_back(next);
        dfs(graph, next, source, distance + 1);
        arr.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<int> graph[9];
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            graph[i].push_back(j);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        arr.push_back(i);
        dfs(graph, i, i, 1);
        arr.pop_back();
    }

    return 0;
}