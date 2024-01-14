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

int gcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }

    int temp;
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

    int a, b;
    int c, d;
    cin >> a >> b >> c >> d;

    int denominator = b * d;
    int numerator = a * d + b * c;

    int divisor = gcd(numerator, denominator);

    cout << numerator / divisor << " " << denominator / divisor;

    return 0;
}
