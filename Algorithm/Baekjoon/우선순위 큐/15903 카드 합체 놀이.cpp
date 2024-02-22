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

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    while (m--)
    {
        // 가장 작은 카드 2개를 뽑는다.
        long long card1 = pq.top();
        pq.pop();
        long long card2 = pq.top();
        pq.pop();

        // 뽑은 카드를 더한 값을 2번 넣는다.
        long long sum = card1 + card2;
        pq.push(sum);
        pq.push(sum);
    }

    long long answer = 0;
    while (!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }

    cout << answer;

    return 0;
}
