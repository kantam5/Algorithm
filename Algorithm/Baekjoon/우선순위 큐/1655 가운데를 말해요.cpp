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

priority_queue<int> smaller;                                // 최대 힙
priority_queue<int, vector<int>, greater<int>> bigger;      // 최소 힙

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int temp;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;

        // samller의 크기는 bigger의 크기보다 1 크거나 같다.
        if (smaller.empty())
        {
            smaller.push(temp);
        }
        else if (smaller.size() == bigger.size())
        {
            smaller.push(temp);
        }
        else
        {
            bigger.push(temp);
        }

        // smaller의 최댓값이 bigger의 최솟값보다 크다면, 그 값을 서로 바꿔야 한다.
        if (!smaller.empty() && !bigger.empty() && smaller.top() > bigger.top())
        {
            // smaller는 최대 힙이므로 최댓값이 top에 위치한다.
            int small_top = smaller.top();
            smaller.pop();

            // bigger는 최소 힙이므로 최솟값이 top에 위치한다.
            int big_top = bigger.top();
            bigger.pop();

            smaller.push(big_top);
            bigger.push(small_top);
        }

        cout << smaller.top() << '\n';
    }

    return 0;
}
