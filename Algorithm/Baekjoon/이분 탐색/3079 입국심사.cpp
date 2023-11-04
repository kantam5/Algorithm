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

vector<unsigned long long> nums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    // 검사받는 총 시간을 이분 탐색한다. 
    // 최솟값은 1, 최댓값은 가장 걸리는 시간이 많은 심사대에서 모두 받았을 경우로 설정했다.
    unsigned long long start = 1;
    unsigned long long end = *max_element(nums.begin(), nums.end()) * M;
    unsigned long long answer = end;
    while (start <= end)
    {
        unsigned long long mid = (start + end) / 2;

        unsigned long long current = 0;

        // mid 시간 까지 각 심사대에서 심사가능한 사람의 수는
        // mid / nums[i]이다.
        for (int i = 0; i < N; ++i)
        {
            current += mid / nums[i];
        }

        // mid 시간까지 검사할 수 있는 사람의 수와 M을 비교하여 범위 조절
        if (current >= M)
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