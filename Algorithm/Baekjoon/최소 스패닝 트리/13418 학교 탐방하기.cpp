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
int parent[1001];

bool compareAscending(edge a, edge b)
{
    return a.dist < b.dist;
}

bool compareDescending(edge a, edge b)
{
    return a.dist > b.dist;
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

    for (int i = 0; i < M + 1; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back({ A, B, C });
    }

    // �־��� ��쿣 ���������� �켱���� �����Ѵ�.
    // �������� ������������ �����Ѵ�.
    sort(edges.begin(), edges.end(), compareAscending);
    for (int i = 0; i <= N; ++i)
    {
        parent[i] = i;
    }

    int uphill_count = 0;
    for (auto edge : edges)
    {
        if (!cycle(edge.n1, edge.n2))
        {
            Union(edge.n1, edge.n2);

            // ������ ���������� ��� count����
            if (edge.dist == 0)
            {
                uphill_count++;
            }
        }
    }

    int maxi = pow(uphill_count, 2);

    // ������ ��쿣 ���������� �켱���� �����Ѵ�.
    // �������� ������������ �����Ѵ�.
    sort(edges.begin(), edges.end(), compareDescending);
    for (int i = 0; i <= N; ++i)
    {
        parent[i] = i;
    }

    uphill_count = 0;
    for (auto edge : edges)
    {
        if (!cycle(edge.n1, edge.n2))
        {
            Union(edge.n1, edge.n2);

            // ������ ���������� ��� count����
            if (edge.dist == 0)
            {
                uphill_count++;
            }
        }
    }

    int mini = pow(uphill_count, 2);

    cout << maxi - mini;

    return 0;
}
