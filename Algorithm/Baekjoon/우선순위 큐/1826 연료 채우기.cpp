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

vector<pair<int, int>> v;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int L, P;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;

        v.push_back(make_pair(a, b));
    }

    cin >> L >> P;

    sort(v.begin(), v.end());

    int answer = 0;
    int current_index = 0;
    while (L > P)
    {
        // 현재 연료로 도달할 수 있는 주유소들의 P를 우선순위 큐에 저장해 둔다.
        while (current_index < N && P >= v[current_index].first)
        {
            pq.push(v[current_index].second);
            current_index++;
        }

        // 현재 연료로 도달할 수 있는 주유소 중에서 가장 연료가 높은 주유소를 방문한다.
        if (!pq.empty())
        {
            P += pq.top();
            pq.pop();

            answer++;
        }
        else
        {
            // 만약 현재 연료로 도달할 수 있는 주유소가 없다면 -1 출력
            answer = -1;
            break;
        }
    }

    cout << answer;

    return 0;
}
