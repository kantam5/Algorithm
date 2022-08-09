#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int paper[2188][2188];

int number_m1 = 0;
int number_0 = 0;
int number_1 = 0;

void solve(int x, int y, int size)
{
    int temp = paper[x][y];

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (temp != paper[i][j])
            {
                solve(x, y, size / 3);
                solve(x + size * 1 / 3, y, size / 3);
                solve(x + size * 2 / 3, y, size / 3);
                solve(x, y + size * 1 / 3, size / 3);
                solve(x + size * 1 / 3, y + size * 1 / 3, size / 3);
                solve(x + size * 2 / 3, y + size * 1 / 3, size / 3);
                solve(x, y + size * 2 / 3, size / 3);
                solve(x + size * 1 / 3, y + size * 2 / 3, size / 3);
                solve(x + size * 2 / 3, y + size * 2 / 3, size / 3);
                return;
            }
        }
    }

    if (temp == -1)
    {
        number_m1++;
    }
    else if (temp == 0)
    {
        number_0++;
    }
    else if (temp == 1)
    {
        number_1++;
    }

    return;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf_s("%d", &paper[i][j]);
        }
    }

    solve(0, 0, N);

    cout << number_m1 << endl << number_0 << endl << number_1 << endl;

    return 0;
}