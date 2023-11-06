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

vector<long long> nums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    long long maxi = 0;
    for (int i = 0; i < M; ++i)
    {
        long long temp;
        cin >> temp;
        nums.push_back(temp);

        maxi = max(maxi, temp);
    }

    if (N <= M)
    {
        cout << N;
        return 0;
    }

    long long start = 0;
    long long end = N * maxi;
    long long total_time = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;

        // 0초일 때, 놀이기구에 모두 들어가 있으니 current를 M에서 시작
        long long current = M;
        for (int i = 0; i < M; ++i)
        {
            current += (mid / nums[i]);
        }

        if (current < N)
        {
            start = mid + 1;
        }
        else
        {
            total_time = mid;
            end = mid - 1;
        }
    }

    // (최소시간 - 1)분 때, 몇 명이 탈 수 있는지 확인
    long long temp_time = total_time - 1;
    long long ridden = M;
    for (int i = 0; i < M; ++i)
    {
        ridden += (temp_time / nums[i]);
    }

    // 마지막 사람이 몇 번 놀이기구에 들어가는지 확인
    for (int i = 0; i < M; ++i)
    {
        // 최소시간과 탐승 시간이 나누어 떨어진다면, 
        // 최소시간 때에 놀이기구에 탑승할 수 있다.
        if (total_time % nums[i] == 0)
        {
            ridden++;
        }
        if (ridden == N)
        {
            cout << i + 1;
            break;
        }
    }

    return 0;
}