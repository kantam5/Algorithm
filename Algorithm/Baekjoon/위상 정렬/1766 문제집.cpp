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

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> indegree;
vector<vector<int>> outdegree;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    indegree.resize(N + 1, 0);
    outdegree.resize(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;

        // B�� Ǯ�����ؼ��� A�� ���� Ǯ��� �Ѵ�.
        indegree[B]++;
        outdegree[A].push_back(B);
    }

    for (int i = 1; i <= N; ++i)
    {
        // ���� ���� Ǯ����� ������ ���� �������� pq�� ����.
        if (indegree[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int current = pq.top();
        pq.pop();

        cout << current << " ";

        // ���� Ǭ ������ outdegree�� �ش��ϴ� �������� indegree�� 1 �پ���.
        for (int i = 0; i < outdegree[current].size(); ++i)
        {
            int next = outdegree[current][i];
            indegree[next]--;

            // outdegree�� 0�� �Ǿ��ٸ� ���� Ǯ �� �����Ƿ�, pq�� �ִ´�.
            if (indegree[next] == 0)
            {
                pq.push(next);
            }
        }
    }

    return 0;
}
