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

string cache[101][101];

string addString(string a, string b)
{
    int sum = 0;
    string result;

    // 1의 자리부터 더하기
    while (!a.empty() || !b.empty() || sum)
    {
        if (!a.empty())
        {
            sum += (int)a.back() - '0';
            a.pop_back();
        }
        if (!b.empty())
        {
            sum += (int)b.back() - '0';
            b.pop_back();
        }

        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    ::reverse(result.begin(), result.end());

    return result;
}

string combination(int n, int r)
{
    string temp = "0";

    if (n == 5 && r == 2)
        int a;

    if (!cache[n][r].empty())
        return cache[n][r];
    else
    {
        if (n == r || r == 0)
        {
            cache[n][r] = "1";
            return "1";
        }
        else
        {
            temp = addString(combination(n - 1, r - 1), combination(n - 1, r));
            cache[n][r] = temp;
            return temp;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int m;

    cin >> n >> m;

    string result = combination(n, m);
    cout << result << endl;

    return 0;
}