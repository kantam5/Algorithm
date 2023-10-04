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

using namespace std;

int N;
char ground[3100][6200];
char star[3][6] =
{
    "  *  ",
    " * * ",
    "*****"
};

void insertStar(int n, int x, int y)
{
    // 계속 쪼개서 n이 1이라면 별을 입력
    if (n == 1)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                ground[x + i][y + j] = star[i][j];
            }
        }

        return;
    }

    insertStar(n / 2, x, y + 3 * n / 2);
    insertStar(n / 2, x + 3 * n / 2, y);
    insertStar(n / 2, x + 3 * n / 2, y + 3 * n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    insertStar(N / 3, 0, 0);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 2 * N - 1; ++j)
        {
            if (ground[i][j] == '*')
            {
                cout << '*';
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}