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

vector<long long> divisor;

long long gcd(long long a, long long b)
{
    if (a < b)
    {
        swap(a, b);
    }

    long long temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;

    // B�� ����� divisor�� ����
    for (int i = 1; i * i <= B; ++i)
    {
        if (B % i == 0)
        {
            divisor.push_back(i);
            if (B / i != i)
            {
                divisor.push_back(B / i);
            }
        }
    }

    long long answer_x = 150'000'000;
    long long answer_y = 150'000'000;
    for (int i = 0; i < divisor.size(); ++i)
    {
        long long x = divisor[i] * A;
        long long y = B / divisor[i];

        long long GCD = gcd(x, y);
        long long LCM = (x * y) / GCD;

        // (x, y)�� �ִ������� A�̸鼭, �ּҰ������ B�� (x, y)
        if (GCD == A && LCM == B)
        {
            if (answer_x + answer_y > x + y)
            {
                answer_x = x;
                answer_y = y;
            }
        }
    }

    cout << answer_x << " " << answer_y;

    return 0;
}
