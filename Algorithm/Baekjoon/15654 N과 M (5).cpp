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
// 중복 불가는 visited설정
bool visited[10000];
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
        if (!visited[next])
        {
            arr.push_back(next);
            visited[next] = true;
            dfs(graph, next, source, distance + 1);
            arr.pop_back();
            visited[next] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    vector<int> graph[10000];
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            graph[v[i]].push_back(v[j]);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        arr.push_back(v[i]);
        visited[v[i]] = true;
        dfs(graph, v[i], v[i], 1);
        arr.pop_back();
        visited[v[i]] = false;
    }

    return 0;
}