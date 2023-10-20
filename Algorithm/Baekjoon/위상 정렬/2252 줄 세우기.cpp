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

int indegree[32001];
vector<int> outdegree[32001];
vector<int> path;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;

        // B�� ��ġ�� ���ؼ��� ������ A�� ���� ���ľ� �Ѵ�. 
        // A�� B�� ��ġ�� ���ؼ��� ������ ���� ���ľ� �Ѵ�.
        indegree[B]++;
        outdegree[A].push_back(B);
    }

    // �տ� �ٸ� �л��� �� �ʿ䰡 ���� �л����� queue�� �ִ´�.
    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int current = q.front();
        path.push_back(current);
        q.pop();

        // current�л��� �տ� �����Ƿ� current�л��� �տ� �־�� �ϴ� �л����� indegree�� 1�����Ѵ�.
        for (int i = 0; i < outdegree[current].size(); ++i)
        {
            int next = outdegree[current][i];

            if (--indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[i] << " ";
    }

    return 0;
}