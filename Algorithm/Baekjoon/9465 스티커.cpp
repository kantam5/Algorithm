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

int cache[2][100001];
int paper[2][100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> paper[0][i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> paper[1][i];
        }

        int maxi = 0;

        cache[0][0] = paper[0][0];
        maxi = max(maxi, cache[0][0]);
        cache[1][0] = paper[1][0];
        maxi = max(maxi, cache[1][0]);

        cache[0][1] = paper[0][1] + paper[1][0];
        maxi = max(maxi, cache[0][1]);
        cache[1][1] = paper[1][1] + paper[0][0];
        maxi = max(maxi, cache[1][1]);

        for (int i = 2; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cache[j][i] = max(paper[j][i] + cache[0][i - 2], paper[j][i] + cache[1][i - 2]);
                if (j == 0)
                {
                    cache[j][i] = max(cache[j][i], paper[0][i] + cache[1][i - 1]);
                }
                else if (j == 1)
                {
                    cache[j][i] = max(cache[j][i], paper[1][i] + cache[0][i - 1]);
                }

                maxi = max(maxi, cache[j][i]);
            }
        }

        cout << maxi << "\n";

        memset(paper, 0, sizeof(paper));
        memset(cache, 0, sizeof(cache));
    }

    return 0;
}