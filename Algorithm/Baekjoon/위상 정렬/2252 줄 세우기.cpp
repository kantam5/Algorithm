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

        // B를 거치기 위해서는 무조건 A가 먼저 거쳐야 한다. 
        // A는 B를 거치기 위해서는 무조건 먼저 거쳐야 한다.
        indegree[B]++;
        outdegree[A].push_back(B);
    }

    // 앞에 다른 학생이 설 필요가 없는 학생부터 queue에 넣는다.
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

        // current학생이 앞에 섰으므로 current학생이 앞에 있어야 하는 학생들의 indegree를 1차감한다.
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