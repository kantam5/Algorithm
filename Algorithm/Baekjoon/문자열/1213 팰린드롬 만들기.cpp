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

    // Ȧ���� �Էµ� ���ĺ��� 2�� �̻��̶�� �縰����� ���� �� ����.
    if (odd_count >= 2)
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    // A���� Z���� �Էµ� Ƚ���� ������ ���
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < alphabet[i] / 2; ++j)
        {
            cout << (char)('A' + i);
        }
    }

    // Ȧ������ �Էµ� ���ĺ��� �߰��� ���
    if (odd_count == 1)
    {
        cout << (char)('A' + odd_index);
    }

    // Z���� A���� �Էµ� Ƚ���� ������ ���
    for (int i = 25; i >= 0; --i)
    {
        for (int j = 0; j < alphabet[i] / 2; ++j)
        {
            cout << (char)('A' + i);
        }
    }

    return 0;
}
