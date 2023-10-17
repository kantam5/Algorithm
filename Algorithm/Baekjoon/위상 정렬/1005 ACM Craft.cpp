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

        // indegree�� 0�̶�� queue�� ����
        queue<int> zero_indegree;
        for (int i = 1; i <= N; ++i)
        {
            if (indegree[i] == 0)
            {
                zero_indegree.push(i);
                indegree[i] = -1;

                // �ʱ� cache
                cache[i] = build_time[i];
            }
        }

        while (!zero_indegree.empty())
        {
            int current = zero_indegree.front();
            zero_indegree.pop();

            // ��� ����
            path.push_back(current);

            // current�� ����� ��带 Ž���Ѵ�.
            for (int i = 0; i < outdegree[current].size(); ++i)
            {
                // current�κ��� ����� next
                int next = outdegree[current][i];

                // next�� indegree �� currrent�� ���� ���޵Ǿ����� ����.
                // next�� indegree�� 0�� �Ǿ��ٸ� queue�� �ִ´�.
                if (--indegree[next] == 0)
                {
                    zero_indegree.push(next);
                    indegree[next] = -1;
                }

                // next�� cache�� current�� cache�� next�� �Ҹ� �ð��� ���� ���� �ִ밪�̴�.
                cache[next] = max(cache[next], cache[current] + build_time[next]);
            }
        }

        // path�� ���� cache�� ä���.
        /*for (int i = 0; i < path.size(); ++i)
        {
            // indegree�� cache �� �ִ밪 + �ڽ��� �Ҹ� �ð�
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