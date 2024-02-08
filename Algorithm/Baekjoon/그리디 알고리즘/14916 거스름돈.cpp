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

    int n;
    cin >> n;

    // 5원으로 모두 줄 수 있는 경우
    if (n % 5 == 0)
    {
        cout << n / 5;
    }
    else
    {
        // 5원으로 줄 수 없는 경우
        int answer = 0;
        while (n > 0)
        {
            // 5로 나누어떨어질 때까지 2 차감
            answer++;
            n -= 2;

            if (n % 5 == 0)
            {
                answer += n / 5;
                cout << answer;
                break;
            }
        }
    }

    // 1이나 3처럼 거슬러 줄 수 없는 경우
    if (n < 0)
    {
        cout << "-1";
    }

    return 0;
}
