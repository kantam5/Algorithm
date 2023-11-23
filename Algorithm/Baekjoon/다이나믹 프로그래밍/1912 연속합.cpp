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

    // 수는 한개 이상 선택해야 하므로 첫 요소로 초기화한다.
    int answer = nums[0];
    int current = nums[0];

    for (int i = 1; i < N; ++i)
    {
        // 현재 배열 내부에 있는 값의 총합이 current이다. 

        // current가 nums[i]보다 작다면 기존의 배열은 버리고 
        // nums[i]를 첫 요소로 하는 새로운 배열을 생성한다.
        current += nums[i];
        current = current < nums[i] ? nums[i] : current;

        // current의 최대값이 답이다.
        answer = max(answer, current);
    }

    cout << answer;

    return 0;
}