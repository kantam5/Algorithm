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

using namespace std;

long long solution(long long A, long long B, long long C)
{
    long long result = 1;

    while (B > 0)
    {
        if (B % 2 == 1)
        {
            result = (result * A) % C;
            // result = ((result % C) * (A % C)) % C;
        }
        B /= 2;

        A = ((A % C) * (A % C)) % C;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A;
    long long B;
    long long C;
    cin >> A >> B >> C;

    cout << solution(A, B, C) << endl;

    return 0;
}