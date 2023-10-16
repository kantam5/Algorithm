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

typedef struct
{
    int x;
    int y;
}edge;

int parent[500'000];

int getParent(int n)
{
    if (parent[n] == n)
    {
        return n;
    }

    return getParent(parent[n]);
}

bool cycle(int x, int y)
{
    int p1 = getParent(x);
    int p2 = getParent(y);
    return p1 == p2;
}

void Union(int x, int y)
{
    x = getParent(x);
    y = getParent(y);

    if (x <= y)
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int n, m;
    vector<edge> edges;

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({ x, y });
    }

    int count = 0;
    int answer = 0;
    for (edge e : edges)
    {
        count++;

        // 현재 검사하는 간선이 사이클이 생긴다면 break
        if (cycle(e.x, e.y))
        {
            answer = count;
            break;
        }
        else
        {
            Union(e.x, e.y);
        }
    }

    cout << answer;

    return 0;
}