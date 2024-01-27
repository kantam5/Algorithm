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

int dist[100'000];
int cost[100'000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> dist[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> cost[i];
    }

    int current = 0;
    long long answer = 0;

    // 현재 지역보다 가격이 싼 지역이 등장할 때까지 현재 지역에서 기름을 구매하고 이동, 이를 반복
    while (current < N)
    {
        int next = N;

        // 현재 지역의 오른쪽 지역 중에서, 현재 지역의 가격보다 기름이 싼 지역이 발견되면 다음 목적지로 설정한다.
        for (int i = current; i < N; ++i)
        {
            if (cost[current] > cost[i])
            {
                next = i;
                break;
            }
        }

        // 다음 지역까지의 거리를 측정
        long long distance = 0;
        for (int i = current; i < next; ++i)
        {
            distance += dist[i];
        }

        // 다음 지역까지 필요한 기름을 현재 지역에서 구매
        answer += distance * cost[current];

        current = next;
    }

    cout << answer;

    return 0;
}
