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
    float dist;
}edge;

int parent[100];

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

    int n;
    cin >> n;

    vector<pair<float, float>> nodes;
    for (int i = 0; i < n; ++i)
    {
        float a, b;
        cin >> a >> b;
        nodes.push_back(make_pair(a, b));
    }

    // 각 노드에서 다른 노드까지의 간선을 구한다.
    vector<edge> edges;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            pair<float, float> n1 = nodes[i];
            pair<float, float> n2 = nodes[j];

            float dist = pow(n2.first - n1.first, 2) + pow(n2.second - n1.second, 2);
            dist = sqrt(dist);

            // i - j로 거리가 dist인 간선
            edges.push_back({ i, j, dist });
        }
    }

    // 크루스칼 알고리즘을 위한 정렬
    sort(edges.begin(), edges.end(), compare);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }

    // 크루스칼 알고리즘으로 최소 비용을 구한다.
    float answer = 0;
    for (auto edge : edges)
    {
        if (!cycle(edge.v1, edge.v2))
        {
            Union(edge.v1, edge.v2);
            answer += edge.dist;
        }
    }

    // 소수점 둘째자리까지 출력
    cout << fixed;
    cout.precision(2);

    cout << answer;

    return 0;
}

