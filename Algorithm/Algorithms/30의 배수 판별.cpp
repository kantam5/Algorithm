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

    // 0�� �����鼭, �� �ڸ����� ���� 3�� ������ 30�� ����̴�.
    // ������ �����Ѵٸ�, ���ڿ��� ������������ �����ϰ� ���
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
