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

vector<int> nums;
vector<int> dists;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, M, L;
    cin >> N >> M >> L;

    nums.push_back(0);
    nums.push_back(L);
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());

    // 휴게소를 세울 수 있는 최소 거리는 중복이 안 되므로 1이다.
    // 최대 거리는 고속도로 마지막에는 세울 수 없으므로 L - 1이다.
    int start = 1;
    int end = L - 1;
    int answer = 0;

    // mid의 주기로 휴게소를 세웠을 때, M과의 비교로 이분 탐색
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int current = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            // 휴게소와 휴게소 사이의 거리 dist
            // dist안에서 세울 수 있는 휴게소의 수는 dist / mid이다.
            // 단, nums[i]의 휴게소에 중복으로 세울 수 없으니 dist % mid == 0이라면 1차감한다.
            int dist = nums[i] - nums[i - 1];

            current += dist / mid;
            if (dist % mid == 0)
            {
                current--;
            }
        }

        if (current <= M)
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << answer;

    return 0;
}