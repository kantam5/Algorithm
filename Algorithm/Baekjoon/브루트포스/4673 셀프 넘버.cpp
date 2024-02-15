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

bool isSelfNumber(int n)
{
    bool out = true;

    // (n - i)가 n의 생성자라면 셀프 넘버가 아니다
    for (int i = 1; i < n; ++i)
    {
        int current = n - i;

        // current의 각 자리수를 더한다
        int current_sum = 0;
        int temp = current;
        while (temp != 0)
        {
            current_sum += (temp % 10);
            temp = temp / 10;
        }

        // (n - i) + ((n - i)의 각 자리수의 합)이 n이라면 i는 n의 생성자이다.
        if (current + current_sum == n)
        {
            out = false;
            break;
        }
    }

    return out;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 10'000; ++i)
    {
        if (isSelfNumber(i))
        {
            cout << i << '\n';
        }
    }

    return 0;
}
