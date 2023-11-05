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

vector<int> nums;

// 기존에 입력된 nums에서 num 이하의 값중에서
// 최댓값을 num으로 교체한다.
void binary_input(int num)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int current = nums[mid];

        if (current < num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    // 이분 탐색 후 start가 적절한 위치로 설정된다.
    nums[start] = num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 첫번째 값은 바로 삽입
    int temp;
    cin >> temp;
    nums.push_back(temp);

    // 입력을 받으면서 검사
    int index = 0;
    for (int i = 1; i < n; ++i)
    {
        int temp_;
        cin >> temp_;

        // 입력 받은 값이 현재 nums의 마지막 수보다 크다면 바로 삽입
        if (nums[index] < temp_)
        {
            nums.push_back(temp_);
            index++;
        }
        // 이하라면 입력받은 값보다 바로 아래로 작은 값을 이분 탐색하여 교체
        else
        {
            binary_input(temp_);
        }
    }

    // nums에 가장 긴 증가하는 부분 수열이 들어간다.
    cout << nums.size();

    return 0;
}