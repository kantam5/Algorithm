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

char alphabet[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        alphabet[s[i] - 'A']++;
    }

    int odd_count = 0;
    int odd_index = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (alphabet[i] % 2 == 1)
        {
            odd_count++;
            odd_index = i;
        }
    }

    // 홀수로 입력된 알파벳이 2개 이상이라면 펠린드롬을 만들 수 없다.
    if (odd_count >= 2)
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    // A부터 Z까지 입력된 횟수의 절반을 출력
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < alphabet[i] / 2; ++j)
        {
            cout << (char)('A' + i);
        }
    }

    // 홀수개로 입력된 알파벳은 중간에 출력
    if (odd_count == 1)
    {
        cout << (char)('A' + odd_index);
    }

    // Z부터 A까지 입력된 횟수의 절반을 출력
    for (int i = 25; i >= 0; --i)
    {
        for (int j = 0; j < alphabet[i] / 2; ++j)
        {
            cout << (char)('A' + i);
        }
    }

    return 0;
}
