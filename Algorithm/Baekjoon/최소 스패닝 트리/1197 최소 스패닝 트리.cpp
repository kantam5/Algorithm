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
    int v1;
    int v2;
    int dist;
}edge;

int parent[10001];

bool compare(const edge edge1, const edge edge2)
{
    return edge1.dist < edge2.dist;
}

// v의 최상위 부모 노드를 반환
int getParent(int v)
{
    if (parent[v] == v)
    {
        return v;
    }

    return getParent(parent[v]);
}

// 현재 사이클이 생기는지(부모 노드가 같은지) 확인
bool Cycle(int v1, int v2)
{
    v1 = getParent(v1);
    v2 = getParent(v2);
    return v1 == v2;
}

// v1과 v2의 부모 노드를 같게 설정
void Union(int v1, int v2)
{
    int p1 = getParent(v1);
    int p2 = getParent(v2);

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
    cin.tie(0);
    cout.tie(nullptr);

    int V, E;
    vector<edge> edges;
    long long answer = 0;

    cin >> V >> E;

    for (int i = 0; i < E; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;

        edges.push_back({ A, B, C });
    }

    // 가중치가 작은 순으로 정렬
    sort(edges.begin(), edges.end(), compare);
    // 초기 부모는 자신으로 설정
    for (int i = 1; i <= V; ++i)
    {
        parent[i] = i;
    }

    for (edge e : edges)
    {
        // 사이클이 생기지 않는다면 간선을 선택하고 Union
        if (!Cycle(e.v1, e.v2))
        {
            answer += e.dist;
            Union(e.v1, e.v2);
        }
    }

    cout << answer;

    return 0;
}