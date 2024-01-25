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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int change = 1000 - N;

    int coins[6] = { 500, 100, 50, 10, 5, 1 };
    int current = 0;

    int answer = 0;

    // 큰 동전부터 시작하여, 최대한 거슬러 줄 수 있을 때까지 준다.
    while (current < 6)
    {
        while (change - coins[current] >= 0)
        {
            change -= coins[current];
            answer++;
        }
        current++;
    }

    cout << answer;

    return 0;
}
