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

int nums[1000];
vector<int> sums;

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

    // x + y + z = k 에서 x + y로 가능한 것을 모두 구해놓는다.
    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            sums.push_back(nums[i] + nums[j]);
        }
    }

    // 수가 큰 것 부터 확인하면 더 빠르게 끝나므로 정렬
    sort(nums, nums + N);
    // 이분 탐색을 위해 합들을 정렬
    sort(sums.begin(), sums.end());

    // 큰 수 부터 탐색한다.
    // x + y = k - z 를 만족하므로 sums에서 (k - z)를 이분탐색하며 발견 시 바로 종료
    for (int k = N - 1; k >= 0; --k)
    {
        for (int z = k; z >= 0; --z)
        {
            if (binary_search(sums.begin(), sums.end(), nums[k] - nums[z]))
            {
                cout << nums[k];
                return 0;
            }
        }
    }

    return 0;
}
