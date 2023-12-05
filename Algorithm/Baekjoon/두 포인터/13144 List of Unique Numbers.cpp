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

int nums[100000];
bool num_count[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    long long answer = 0;
    int start = 0;
    int end = 0;
    while (true)
    {
        // start를 더 이상 늘릴 수 없을 때까지 반복한다.
        if (start >= N)
        {
            break;
        }

        // start부터 중복되는 값이 없을 때까지 수열을 늘린다.
        // 혹은 end가 N까지 도달하여 더 이상 수열을 늘릴 수 없을 때까지 늘린다.
        while (end < N && num_count[nums[end]] == false)
        {
            num_count[nums[end]] = true;
            end++;
        }

        // start에서 end까지 start를 포함하여 만들 수 있는 수열의 개수는 end - start이다.
        answer += (end - start);

        // start를 앞으로 늘린다.
        num_count[nums[start]] = false;
        start++;
    }

    cout << answer;

    return 0;
}
