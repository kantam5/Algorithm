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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int temp;
            cin >> temp;

            pq.push(temp);

            // 우선순위 큐의 사이즈가 N보다 크다면 pop
            // 현재까지 가장 작은 수가 pop된다.
            if (pq.size() > N)
            {
                pq.pop();
            }
        }
    }

    cout << pq.top();

    return 0;
}
