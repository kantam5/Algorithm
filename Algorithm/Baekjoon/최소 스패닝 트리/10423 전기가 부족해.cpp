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
    int v1;
    int v2;
    int dist;
}edge;
vector<edge> edges;
int parent[1001];
vector<int> elect;

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

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < K; ++i)
    {
        int temp;
        cin >> temp;
        elect.push_back(temp);
    }

    for (int i = 1; i <= N; ++i)
    {
        parent[i] = i;
    }

    // 발전소 노드는 미리 하나의 그룹으로 만들어 놓는다.
    for (int i = 1; i < K; ++i)
    {
        Union(elect[0], elect[i]);
    }

    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({ u, v, w });
    }

    sort(edges.begin(), edges.end(), compare);

    // 크루스칼 알고리즘 실시
    int answer = 0;
    for (auto edge : edges)
    {

        if (!cycle(edge.v1, edge.v2))
        {
            answer += edge.dist;
            Union(edge.v1, edge.v2);
        }
    }

    cout << answer;

    return 0;
}
