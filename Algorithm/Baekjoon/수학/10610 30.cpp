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

    string s;
    cin >> s;

    int sum = 0;
    bool flag = false;
    for (int i = 0; i < s.size(); ++i)
    {
        sum += s[i] - '0';
        if (s[i] == '0')
        {
            flag = true;
        }
    }

    // 0이 있으면서, 각 자리수의 합이 3의 배수라면 30의 배수이다.
    // 조건을 만족한다면, 문자열을 내림차순으로 정렬하고 출력
    if (sum % 3 == 0 && flag)
    {
        sort(s.begin(), s.end(), greater<>());
        cout << s;
    }
    else
    {
        cout << -1;
    }

    return 0;
}
