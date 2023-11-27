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

int nums[200'000];
int num_count[100'001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    // start와 end 모두 0에서부터 시작한다.
    int start = 0;
    int end = 0;

    int answer = 0;
    // end가 N 미만까지 검사한다.
    while (end < N)
    {
        // num[end]는 현재 수열에 추가하려는 수이다.
        // 현재 추가하려는 수가 K개 미만일 경우에는 추가할 수 있다.
        if (num_count[nums[end]] < K)
        {
            // end 인덱스의 수를 수열에 추가한다.
            num_count[nums[end]]++;
            end++;
            answer = max(answer, end - start);
        }
        // 추가할 수 없을 경우에는 start를 앞으로 전진시켜
        // 추가하려는 수를 추가할 수 있을 때까지 제거한다.
        else
        {
            num_count[nums[start]]--;
            start++;
        }
    }

    cout << answer;

    return 0;
}
