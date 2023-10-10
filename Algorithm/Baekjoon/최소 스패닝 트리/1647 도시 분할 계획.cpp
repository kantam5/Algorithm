#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    int v1;
    int v2;
    int dist;
}edge;

int parent[100001];

bool compare(const edge e1, const edge e2)
{
    return e1.dist < e2.dist;
}

int getParent(int v)
{
    if (v == parent[v])
    {
        return v;
    }

    return getParent(parent[v]);
}

bool cycle(int v1, int v2)
{
    v1 = getParent(v1);
    v2 = getParent(v2);

    return v1 == v2;
}

void Union(int v1, int v2)
{
    int p1 = getParent(v1);
    int p2 = getParent(v2);

    if (p1 <= p2)
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

    int N, M;
    vector<edge> edges;
    vector<edge> answer_edges;
    int answer = 0;

    cin >> N >> M;

    // ���� 2����� ���� ������ �ʿ䰡 ����.
    if (N == 2)
    {
        cout << 0;

        return 0;
    }

    for (int i = 0; i < M; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;

        edges.push_back({ A, B, C });
    }

    sort(edges.begin(), edges.end(), compare);
    for (int i = 0; i < 100001; ++i)
    {
        parent[i] = i;
    }

    for (edge e : edges)
    {
        if (!cycle(e.v1, e.v2))
        {
            Union(e.v1, e.v2);
            answer_edges.push_back(e);
        }

        // ������ ���ҵǱ⿡ ������ N - 2��ŭ �����ϸ�
        // ���ҵǸ鼭 �ּ��� ����ġ�� ���� �� �ִ�.
        // �������� ���� 2������ �������� �ʴ´ٴ� ��
        if (answer_edges.size() == N - 2)
        {
            break;
        }
    }

    for (edge e : answer_edges)
    {
        answer += e.dist;
    }

    cout << answer;

    return 0;
}