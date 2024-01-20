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
vector<int> answer;

int gcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }

    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
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
    sort(nums.begin(), nums.end());

    // 인접한 두 수의 차의 최대공약수를 구한다.
    int GCD = nums[1] - nums[0];
    for (int i = 2; i < N; ++i)
    {
        GCD = gcd(GCD, nums[i] - nums[i - 1]);
    }

    // 최대공약수의 약수를 구한다.
    for (int i = 2; i * i <= GCD; ++i)
    {
        if (GCD % i == 0)
        {
            answer.push_back(i);
            if (i != GCD / i)
            {
                answer.push_back(GCD / i);
            }
        }
    }
    answer.push_back(GCD);

    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << " ";
    }

    return 0;
}
