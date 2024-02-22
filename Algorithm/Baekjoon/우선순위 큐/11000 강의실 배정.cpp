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

vector<pair<int, int>> lecture;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int S, T;
        cin >> S >> T;
        lecture.push_back(make_pair(S, T));
    }

    sort(lecture.begin(), lecture.end());

    pq.push(lecture[0].second);
    int answer = 1;

    for (int i = 1; i < N; ++i)
    {
        int current = pq.top();

        // 가장 빨리 끝나는 수업이 i번째 수업의 시작시간보다 빨리 끝나는 경우
        // i번째 수업과 같은 강의실에서 진행할 수 있다. 
        // 늦게 끝나는 경우 다른 강의실에서 진행해야 한다. 
        if (current <= lecture[i].first)
        {
            pq.pop();
            pq.push(lecture[i].second);
        }
        else
        {
            pq.push(lecture[i].second);
        }

        // pq의 size는 현재 사용하는 강의실의 수이다.
        answer = max(answer, (int)pq.size());
    }

    cout << answer;

    return 0;
}
