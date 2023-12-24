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
char gender[1001];

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

    int N, M;
    cin >> N >> M;

    // �б��� ������ �Է¹޴´�.
    for (int i = 1; i <= N; ++i)
    {
        cin >> gender[i];
    }

    for (int i = 0; i < M; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;

        // ����� �б��� ������ ���� �ٸ� ��쿡�� �������� �߰��Ѵ�.
        if (gender[u] != gender[v])
        {
            edges.push_back({ u, v, d });
        }
    }

    // ũ�罺Į �˰��� �ǽ�
    for (int i = 1; i <= N; ++i)
    {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), compare);

    int answer = 0;
    int edge_count = 0;
    for (auto edge : edges)
    {
        if (!cycle(edge.v1, edge.v2))
        {
            answer += edge.dist;
            edge_count++;
            Union(edge.v1, edge.v2);
        }
    }

    // ������ ������ ���� (�б��� �� - 1)���� �۴ٸ� ��� �б��� ������� �ʾ����Ƿ� -1 ���
    if (edge_count < N - 1)
    {
        cout << "-1";
    }
    else
    {
        cout << answer;
    }

    return 0;
}
