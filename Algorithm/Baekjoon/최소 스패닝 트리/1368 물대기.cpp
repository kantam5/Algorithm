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
#include <sstream>
#include <cstdlib>

using namespace std;

typedef struct
{
    int n1;
    int n2;
    int dist;
}edge;

vector<edge> edges;
int parent[301];

bool compare(edge a, edge b)
{
    return a.dist < b.dist;
}

int getParent(int n)
{
    if (n == parent[n])
    {
        return n;
    }
    return getParent(parent[n]);
}

bool cycle(int n1, int n2)
{
    n1 = getParent(n1);
    n2 = getParent(n2);
    return n1 == n2;
}

void Union(int n1, int n2)
{
    int p1 = getParent(n1);
    int p2 = getParent(n2);
    if (p1 < p2)
    {
        parent[p2] = p1;
    }
    else
    {
        parent[p1] = p2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 우물을 파는 경우엔 0번 노드와 연결시킨다.
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;

        edges.push_back({ i + 1, 0, temp });
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int temp;
            cin >> temp;

            // 0번 노드는 우물을 파는 경우이므로 각 노드에 +1을 처리하여 간선에 넣는다.
            if (i != j)
            {
                edges.push_back({ i + 1, j + 1, temp });
            }
        }
    }

    // 크루스칼 알고리즘 실시
    sort(edges.begin(), edges.end(), compare);

    for (int i = 0; i <= N; ++i)
    {
        parent[i] = i;
    }

    int answer = 0;
    for (auto edge : edges)
    {
        if (!cycle(edge.n1, edge.n2))
        {
            Union(edge.n1, edge.n2);
            answer += edge.dist;
        }
    }

    cout << answer;

    return 0;
}
