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

// 오름차순 우선순위 큐
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
        int temp;
        cin >> temp;

        pq.push(temp);
    }

    // 카드 수가 가장 적은 2개의 묶음을 합친다.
    // 합쳐진 묶음을 다시 우선순위 큐에 넣는다.
    // 모든 카드 묶음이 합쳐질 때까지 반복
    int answer = 0;
    while (pq.size() > 1)
    {
        int deck1 = pq.top();
        pq.pop();
        int deck2 = pq.top();
        pq.pop();

        answer += (deck1 + deck2);

        pq.push((deck1 + deck2));
    }

    cout << answer;

    return 0;
}
