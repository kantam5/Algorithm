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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    bool flag = false;

    // 수열의 가장 오른쪽부터 바로 왼쪽 원소가 자신보다 작은지 검사한다.
    for (int i = N - 1; i > 0; --i)
    {
        // 작다면 i - 1 원소의 오른쪽의 원소들 중 i - 1 원소보다 큰 값 중 가장 작은 값을 가지는 인덱스를 찾는다.
        if (nums[i - 1] < nums[i])
        {
            int index = i;

            for (int j = i; j < N; ++j)
            {
                if (nums[i - 1] < nums[j] && nums[index] > nums[j])
                {
                    index = j;
                }
            }

            // index와 i - 1의 원소를 swap
            swap(nums[i - 1], nums[index]);

            // i - 1의 오른쪽을 오름차순으로 정렬한다.
            sort(nums.begin() + i, nums.end());

            flag = true;

            break;
        }
    }

    if (flag)
    {
        for (int i = 0; i < N; ++i)
        {
            cout << nums[i] << " ";
        }
    }
    else
    {
        // 순열의 마지막 값인 경우 -1을 출력
        cout << "-1";
    }

    return 0;
}
