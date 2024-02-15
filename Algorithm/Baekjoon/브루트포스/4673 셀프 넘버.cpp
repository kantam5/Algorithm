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

    // (n - i)�� n�� �����ڶ�� ���� �ѹ��� �ƴϴ�
    for (int i = 1; i < n; ++i)
    {
        int current = n - i;

        // current�� �� �ڸ����� ���Ѵ�
        int current_sum = 0;
        int temp = current;
        while (temp != 0)
        {
            current_sum += (temp % 10);
            temp = temp / 10;
        }

        // (n - i) + ((n - i)�� �� �ڸ����� ��)�� n�̶�� i�� n�� �������̴�.
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
