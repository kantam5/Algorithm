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

char m[11][11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int H, W;
        cin >> H >> W;

        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                cin >> m[i][j];
            }
        }

        // 불판 자체를 뒤집기
        for (int i = 0; i < H; ++i)
        {
            for (int j = W - 1; j >= 0; --j)
            {
                cout << m[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}
