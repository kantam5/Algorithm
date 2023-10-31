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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, K;
        cin >> n >> K;

        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }

        sort(nums.begin(), nums.end());

        // 두 수의 합과 K의 차의 절대값의 최솟값인 mini
        // mini인 경우의 조합의 수 answer
        int mini = INT_MAX;
        int answer = 1;

        // 수열의 처음부터 끝까지 검사
        // K와의 차이에 따라 범위를 달리하며 이분 탐색
        // i에서의 다른 수와의 합의 차이 중 가장 작은 값이 current에 들어간다.
        for (int i = 0; i < n; ++i)
        {
            int current = INT_MAX;

            // 서로 다른 수의 합이므로 i + 1에서부터 검사한다.
            int start = i + 1;
            int end = n - 1;
            while (start <= end)
            {
                int mid = (start + end) / 2;

                // i와 mid에서의 합과 K와의 차이 중 가장 작은 값인 current
                current = min(current, abs(K - (nums[i] + nums[mid])));

                // i와 mid에서의 합과 K와의 차이에 따라 범위 조절
                if (nums[i] + nums[mid] >= K)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            // i와 mid에서의 합과 K와의 차이가 mini와 같다면 answer 증가
            if (current == mini)
            {
                answer++;
            }
            // 더 작다면 mini를 갱신
            else if (current < mini)
            {
                mini = current;
                answer = 1;
            }
        }

        cout << answer << '\n';

        nums.clear();
    }

    return 0;
}