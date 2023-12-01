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

long long cache[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    // ���� ������� ���� ���ؾ� �Ѵ�.
    // ������� ���� O(N * log(N))�� �ð����⵵�� ���Ѵ�.
    for (int i = 1; i <= 1000000; ++i)
    {
        for (int j = 1; i * j <= 1000000; ++j)
        {
            cache[i * j] += i;
        }
    }
    // ���ؾ� �ϴ� ���� g(x)�̹Ƿ� g(x) = g(x - 1) + f(x)�̴�. 
    // ���� ������ g(x)�� ���Ѵ�.
    for (int i = 2; i <= 1000000; ++i)
    {
        cache[i] += cache[i - 1];
    }

    while (T--)
    {
        int N;
        cin >> N;

        // g(N)�� ����Ѵ�.
        cout << cache[N] << '\n';
    }

    return 0;
}
