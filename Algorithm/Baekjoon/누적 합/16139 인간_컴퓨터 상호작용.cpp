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

using namespace std;

int alpha[26][200000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;

    // ���ڿ��� ó������ �����Ͽ� i��°���� ���� ���ĺ��� �迭�� ����
    alpha[S[0] - 'a'][0]++;
    for (int i = 1; i < S.size(); ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            // i��° ���ڿ��� j�� ���, ���� j�� ������ Ƚ������ + 1
            if (j == S[i] - 'a')
            {
                alpha[j][i] = alpha[j][i - 1] + 1;
            }
            else
            {
                alpha[j][i] = alpha[j][i - 1];
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        char a;
        int l, r;
        cin >> a >> l >> r;

        // l���� r���� a�� �󸶸�ŭ ���Դ��� ���
        if (l == 0)
        {
            cout << alpha[a - 'a'][r] << '\n';
        }
        else
        {
            cout << alpha[a - 'a'][r] - alpha[a - 'a'][l - 1] << '\n';
        }
    }

    return 0;
}