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

    // �����Դ� 0���� ������ �� ����, start���ٴ� end�� Ŀ�� �Ѵ�.
    long long start = 1;
    long long end = 2;

    bool flag = false;
    while (start < end)
    {
        // ���� start�� end�϶��� G�� current
        int current = pow(end, 2) - pow(start, 2);

        // end�� ���� ������ �������� ���
        if (current == G)
        {
            flag = true;
            cout << end << '\n';
        }

        // current�� ���϶�� ���� �����Ը� �� �÷��� �Ѵ�.
        if (current <= G)
        {
            end++;
        }
        else
        {
            start++;
        }
    }

    // ������ �����԰� ���� ���
    if (flag == false)
    {
        cout << "-1";
    }

    return 0;
}
