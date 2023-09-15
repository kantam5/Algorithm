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

int cache[1001] = { 1 };
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    if (N == 1)
    {
        cout << "1" << '\n';
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int maxi = 0;

    cache[0] = 1;

    for (int i = 1; i < v.size(); i++)
    {
        int temp = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[i] > v[j])
            {
                temp = max(temp, cache[j]);
            }
        }
        cache[i] = temp + 1;

        maxi = max(maxi, cache[i]);
    }

    cout << maxi << "\n";

    return 0;
}