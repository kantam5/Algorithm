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

        // x, y, z ��ǥ�� ��� ���� �Է¹޴´�.
        node_x.push_back({ i, x });
        node_y.push_back({ i, y });
        node_z.push_back({ i, z });
    }

    // ��ǥ ��ġ ������ ����
    sort(node_x.begin(), node_x.end(), compareNodeData);
    sort(node_y.begin(), node_y.end(), compareNodeData);
    sort(node_z.begin(), node_z.end(), compareNodeData);

    for (int i = 1; i < N; ++i)
    {
        // ũ�罺Į �˰����� �ּ� �Ÿ��� ������ �����ϴ� �˰����̴�. 
        // �ּ� �Ÿ��� �� �� �ִ� ������ �ĺ����� �� ���� �ٷ� ���� ������ �Ÿ��� �ȴ�.
        // A -> B -> C ������ x��ǥ�� ��ġ������ ��, 
        // A -> C�� ���� �Ÿ��� A -> B -> C�� ���� �Ÿ��� �����Ƿ�, ���� �ĺ��� ���� �ʾƵ� �����ϴ�.
        edges.push_back({ node_x[i - 1].node, node_x[i].node, node_x[i].dist - node_x[i - 1].dist });
        edges.push_back({ node_y[i - 1].node, node_y[i].node, node_y[i].dist - node_y[i - 1].dist });
        edges.push_back({ node_z[i - 1].node, node_z[i].node, node_z[i].dist - node_z[i - 1].dist });
    }

    // ũ�罺Į �˰��� �ǽ�
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
