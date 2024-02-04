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

int alphabet[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());

        // ���ĺ� ���� ��� �ڸ����� �ԷµǾ����� Ȯ��
        for (int j = s.length() - 1; j >= 0; --j)
        {
            long long temp = pow(10, j);
            alphabet[s[j] - 'A'] += temp;
        }
    }

    // �������� ����
    sort(alphabet, alphabet + 26, greater<>());

    int answer = 0;
    int current = 9;
    for (int i = 0; i < 26; ++i)
    {
        if (alphabet[i] == 0)
        {
            continue;
        }
        answer += alphabet[i] * current;
        current--;
    }

    cout << answer;

    return 0;
}
