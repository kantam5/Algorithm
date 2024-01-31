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

    string S;
    cin >> S;

    int count_0 = 0;
    int count_1 = 0;

    // 0과 1의 구역 중에서 더 적은 수의 구역을 뒤집는다. 
    // 다음 문자와 다르다면 한 구역 종료
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] != S[i + 1])
        {
            if (S[i] == '0')
            {
                count_0++;
            }
            else
            {
                count_1++;
            }
        }
    }

    cout << min(count_0, count_1);

    return 0;
}
