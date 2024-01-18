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

vector<int> nums;

int gcd(int A, int B)
{
    if (A < B)
    {
        swap(A, B);
    }

    int temp;
    while (B != 0)
    {
        temp = A % B;
        A = B;
        B = temp;
    }

    return A;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;

        nums.push_back(temp);
    }

    // 가로수 사이의 간격의 최소공배수를 구한다.
    int GCD = nums[1] - nums[0];
    for (int i = 1; i < nums.size() - 1; ++i)
    {
        GCD = gcd(GCD, nums[i + 1] - nums[i]);
    }

    // 첫 가로수와 마지막 가로수 사이의 거리
    int range = nums[N - 1] - nums[0];

    // range사이에 GCD의 간격으로 심을 수 있는 가로수의 수
    int answer = (range / GCD) - 1;
    // range 양 끝의 가로수는 제외한 이미 심어져 있는 가로수는 뺀다.
    answer -= (N - 2);

    cout << answer;

    return 0;
}
