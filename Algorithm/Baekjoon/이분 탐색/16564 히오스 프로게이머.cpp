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

using namespace std;

vector<int> levels;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, K;
    int answer = 0;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        int level;
        cin >> level;
        levels.push_back(level);
    }

    // 입력받은 레벨을 정렬한다.
    sort(levels.begin(), levels.end());

    // 현재 만들 수 있는 최소 레벨인 levels[0]이 start가 된다.
    int start = levels[0];
    // 현재 만들 수 있는 최대 레벨인 levels[N - 1] + k가 end가 된다.
    int end = levels[N - 1] + K;
    while (start <= end)
    {
        // mid까지 레벨을 올렸을 경우를 검사한다.
        int mid = (start + end) / 2;

        // 레벨을 mid까지 올릴 때까지 필요한 레벨의 총합
        long long need_levels = 0;
        for (int i = 0; i < N; ++i)
        {
            int need_level = mid - levels[i];
            if (need_level > 0)
            {
                need_levels += need_level;
            }
        }

        // 올려여할 레벨이 K보다 적다면 올려야할 레벨을 증가시킨다.
        if (need_levels <= K)
        {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}