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

    int answer = 0;

    // 금칠할 돌상의 배열의 첫 돌상이 왼쪽인 경우와 오른쪽인 경우를 나눠서 생각한다. 
    // 왼쪽을 중점으로 생각한 배열에서의 깨달음 양인 left
    int left = 0;
    // 오른쪽을 중점으로 생각한 배열에서의 깨달음 양인 right
    int right = 0;

    for (int i = 0; i < N; ++i)
    {
        // 현재 돌상은 배열안에 들어와 있다고 가정한다. 
        // 현재 돌상이 왼쪽인 경우에는 left는 1 증가하고, right는 1 감소한다.
        if (nums[i] == 1)
        {
            left++;
            right--;
        }
        // 현재 돌상이 오른쪽인 경우에는 left는 1 감소하고, right는 1 증가한다.
        else
        {
            left--;
            right++;
        }
        // 현재 배열의 깨달음 값이 0미만이라면 현재 배열을 버린다.
        left = left < 0 ? 0 : left;
        right = right < 0 ? 0 : right;

        // 현재 배열 2개의 깨달음 양의 최대값이 답이다.
        int maxi = max(left, right);
        answer = max(answer, maxi);
    }

    cout << answer;

    return 0;
}