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

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    int start = round((n / 100.f) * 15);
    int end = n - start;

    int avg = 0;
    for (int i = start; i < end; ++i)
    {
        avg += v[i];
    }

    cout << round(avg / (n - 2.f * start));

    return 0;
}