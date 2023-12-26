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
    int node;
    int dist;
}node_data;

typedef struct
{
    int n1;
    int n2;
    int dist;
}edge;

vector<node_data> node_x;
vector<node_data> node_y;
vector<node_data> node_z;

vector<edge> edges;

int parent[100000];

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

bool compareNodeData(node_data a, node_data b)
{
    return a.dist < b.dist;
}

bool compareEdge(edge a, edge b)
{
    return a.dist < b.dist;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;

        // x, y, z 좌표를 모두 따로 입력받는다.
        node_x.push_back({ i, x });
        node_y.push_back({ i, y });
        node_z.push_back({ i, z });
    }

    // 좌표 위치 순으로 정렬
    sort(node_x.begin(), node_x.end(), compareNodeData);
    sort(node_y.begin(), node_y.end(), compareNodeData);
    sort(node_z.begin(), node_z.end(), compareNodeData);

    for (int i = 1; i < N; ++i)
    {
        // 크루스칼 알고리즘은 최소 거리의 간선을 선택하는 알고리즘이다. 
        // 최소 거리가 될 수 있는 간선의 후보들은 한 노드와 바로 옆의 노드와의 거리가 된다.
        // A -> B -> C 순으로 x좌표가 위치해있을 때, 
        // A -> C로 가는 거리는 A -> B -> C로 가는 거리와 같으므로, 굳이 후보에 넣지 않아도 무방하다.
        edges.push_back({ node_x[i - 1].node, node_x[i].node, node_x[i].dist - node_x[i - 1].dist });
        edges.push_back({ node_y[i - 1].node, node_y[i].node, node_y[i].dist - node_y[i - 1].dist });
        edges.push_back({ node_z[i - 1].node, node_z[i].node, node_z[i].dist - node_z[i - 1].dist });
    }

    // 크루스칼 알고리즘 실시
    sort(edges.begin(), edges.end(), compareEdge);

    for (int i = 0; i < N; ++i)
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
