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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int G;
    cin >> G;

    // 몸무게는 0에서 시작할 수 없고, start보다는 end가 커야 한다.
    long long start = 1;
    long long end = 2;

    bool flag = false;
    while (start < end)
    {
        // 현재 start와 end일때의 G인 current
        int current = pow(end, 2) - pow(start, 2);

        // end가 현재 가능한 몸무게일 경우
        if (current == G)
        {
            flag = true;
            cout << end << '\n';
        }

        // current가 이하라면 현재 몸무게를 더 늘려야 한다.
        if (current <= G)
        {
            end++;
        }
        else
        {
            start++;
        }
    }

    // 가능한 몸무게가 없는 경우
    if (flag == false)
    {
        cout << "-1";
    }

    return 0;
}
