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

long long gcd(long long A, long long B)
{
    if (A < B)
    {
        swap(A, B);
    }

    long long temp;
    while (B != 0)
    {
        temp = A % B;
        A = B;
        B = temp;
    }

    return A;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;

    int diff = gcd(A, B);

    cout << string(diff, '1');

    return 0;
}
