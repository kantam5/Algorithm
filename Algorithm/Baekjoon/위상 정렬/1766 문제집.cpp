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

        // B를 풀기위해서는 A를 먼저 풀어야 한다.
        indegree[B]++;
        outdegree[A].push_back(B);
    }

    for (int i = 1; i <= N; ++i)
    {
        // 현재 먼저 풀어야할 문제가 없는 문제부터 pq에 들어간다.
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

        // 현재 푼 문제의 outdegree에 해당하는 문제들의 indegree가 1 줄어든다.
        for (int i = 0; i < outdegree[current].size(); ++i)
        {
            int next = outdegree[current][i];
            indegree[next]--;

            // outdegree가 0이 되었다면 이제 풀 수 있으므로, pq에 넣는다.
            if (indegree[next] == 0)
            {
                pq.push(next);
            }
        }
    }

    return 0;
}
