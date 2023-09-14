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

using namespace std;

int cache[1002];
int card[1002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        int temp;
        cin >> temp;
        card[i] = temp;
    }

    for (int i = 1; i <= N; ++i)
    {
        cache[i] = card[i];
    }

    cache[1] = card[1];
    cache[2] = min(card[1] + card[1], card[2]);

    for (int i = 3; i <= N; ++i)
    {
        for (int j = i; j > 1; --j)
        {
            cache[i] = min(cache[i], cache[j] + cache[i - j]);
        }
        // cache[i] = max(card[i], card[1] + cache[i - 1]);
    }

    cout << cache[N] << endl;

    return 0;
}