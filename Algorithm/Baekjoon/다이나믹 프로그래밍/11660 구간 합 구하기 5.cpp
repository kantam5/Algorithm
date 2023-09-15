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

int cache[1025][1025];
int arr[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cache[i][j] = cache[i - 1][j] + cache[i][j - 1] + arr[i][j] - cache[i - 1][j - 1];
        }
    }

    while (M--)
    {
        int x1;
        int y1;
        int x2;
        int y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = cache[x2][y2] - cache[x1 - 1][y2] - cache[x2][y1 - 1] + cache[x1 - 1][y1 - 1];
        cout << result << '\n';
    }

    return 0;
}