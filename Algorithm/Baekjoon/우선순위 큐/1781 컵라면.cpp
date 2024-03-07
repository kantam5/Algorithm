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

priority_queue<int> pq;
vector<int> values[200'001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int deadline, value;
        cin >> deadline >> value;

        // deadline까지 풀 수 있는 문제
        values[deadline].push_back(value);
    }

    // 첫날에 데드라인이 많이 남은 문제를 풀면 이후 풀 수 있는 문제가 없으므로 N번 날짜에 풀 문제부터 선택한다. 
    // i번 날짜에 풀 수 있는 문제는 (i <= 데드라인)인 문제이다. 
    int answer = 0;
    for (int i = N; i > 0; --i)
    {
        // pq에는 데드라인이 i이상인 문제만 들어가게 된다. 
        // 그러므로 pq의 top이 i번 날짜에 풀 수 있는 문제 중에서 value가 가장 높은 문제가 된다.
        for (int value : values[i])
        {
            pq.push(value);
        }

        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;

    return 0;
}
