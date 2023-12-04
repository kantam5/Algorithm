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

vector<long long> nums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        long long temp;
        cin >> temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());

    long long mini = LLONG_MAX;
    long long answer[3];
    // 배열 중 하나의 용액을 먼저 선택한다.
    // 선택하는 순서는 0에서부터 N - 1까지이다.
    for (int i = 0; i < N; ++i)
    {
        // 선택한 용액 뒤의 배열에서 두 포인터를 실시
        int start = i + 1;
        int end = N - 1;
        while (start < end)
        {
            // 현재 선택한 용액과 start, end에서의 용액의 총합
            long long current = nums[i] + nums[start] + nums[end];
            if (abs(current) < abs(mini))
            {
                // 0에 가장 가까운 용액을 답으로 설정
                mini = current;
                answer[0] = nums[i];
                answer[1] = nums[start];
                answer[2] = nums[end];
            }

            if (current < 0)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    cout << answer[0] << " " << answer[1] << " " << answer[2];

    return 0;
}
