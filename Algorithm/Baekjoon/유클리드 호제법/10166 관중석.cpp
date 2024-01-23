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

// 좌석을 분수로 표현
bool nums[2001][2001];

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

    int D1, D2;
    cin >> D1 >> D2;

    int answer = 0;
    for (int i = D1; i <= D2; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            // i / j를 기약분수로 표현했을 때, 같은 값을 가진다면 가려진다.
            // 이미 i / j가 가려졌다면, answer에 추가하지 않는다.
            int GCD = gcd(i, j);
            int numerator = j / GCD;
            int denominator = i / GCD;
            if (nums[numerator][denominator] == false)
            {
                answer++;
                nums[numerator][denominator] = true;
            }
        }
    }

    cout << answer;

    return 0;
}
