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

using namespace std;

int nums[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // 수열을 입력받고 정렬한다.
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
    sort(nums, nums + N);

    int start = 0;
    int end = 0;
    int answer = INT_MAX;
    while (start <= end && end < N)
    {
        int current = nums[end] - nums[start];

        // start와 end의 차이가 M이상이라면 답을 갱신한다. 
        // 차이를 더 줄이기 위해 start를 증가시킨다.
        if (current >= M)
        {
            answer = min(answer, current);
            start++;
        }
        // 미만이라면 차이를 더 늘리기 위해 end를 증가시킨다.
        else
        {
            end++;
        }
    }

    cout << answer;

    return 0;
}
