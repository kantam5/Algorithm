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

    // 내림차순 정렬
    sort(nums, nums + N, greater<int>());

    // i번째 로프가 버틸 수 있는 무게는 nums[i] * (현재까지의 로프 수)이다. 
    // 0번째 로프부터 무게를 위의 방법으로 비교하며 최대 무게를 찾는다.
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        answer = max(answer, (i + 1) * nums[i]);
    }

    cout << answer;

    return 0;
}
