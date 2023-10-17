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

int N, K, W;
int build_time[1001];
int indegree[1001];
vector<int> outdegree[1001];
vector<int> priority[1001];
vector<int> path;
int cache[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> N >> K;

        for (int i = 1; i <= N; ++i)
        {
            cin >> build_time[i];
        }

        for (int i = 0; i < K; ++i)
        {
            int n1, n2;
            cin >> n1 >> n2;

            indegree[n2]++;
            outdegree[n1].push_back(n2);
            priority[n2].push_back(n1);
        }

        cin >> W;

        // indegree가 0이라면 queue에 저장
        queue<int> zero_indegree;
        for (int i = 1; i <= N; ++i)
        {
            if (indegree[i] == 0)
            {
                zero_indegree.push(i);
                indegree[i] = -1;

                // 초기 cache
                cache[i] = build_time[i];
            }
        }

        while (!zero_indegree.empty())
        {
            int current = zero_indegree.front();
            zero_indegree.pop();

            // 경로 저장
            path.push_back(current);

            // current여 연결된 노드를 탐색한다.
            for (int i = 0; i < outdegree[current].size(); ++i)
            {
                // current로부터 연결된 next
                int next = outdegree[current][i];

                // next의 indegree 중 currrent는 지금 도달되었으니 뺀다.
                // next의 indegree가 0이 되었다면 queue에 넣는다.
                if (--indegree[next] == 0)
                {
                    zero_indegree.push(next);
                    indegree[next] = -1;
                }

                // next의 cache는 current의 cache와 next의 소모 시간을 합한 값의 최대값이다.
                cache[next] = max(cache[next], cache[current] + build_time[next]);
            }
        }

        // path를 따라 cache를 채운다.
        /*for (int i = 0; i < path.size(); ++i)
        {
            // indegree의 cache 중 최대값 + 자신의 소모 시간
            int max_cache = 0;
            for (int j = 0; j < priority[path[i]].size(); ++j)
            {
                max_cache = max(max_cache, cache[priority[path[i]][j]]);
            }

            cache[path[i]] = max_cache + build_time[path[i]];
        }*/

        cout << cache[W] << '\n';

        memset(build_time, 0, sizeof(build_time));
        memset(indegree, 0, sizeof(indegree));
        memset(cache, 0, sizeof(cache));
        for (int i = 1; i <= N; ++i)
        {
            outdegree[i].clear();
            priority[i].clear();
        }
        path.clear();
    }

    return 0;
}