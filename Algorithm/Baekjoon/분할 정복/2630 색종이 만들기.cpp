#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int paper[128][128];

int white = 0;
int blue = 0;

int square(int x1, int x2, int y1, int y2)
{
    int result = 0;
    int temp = paper[x1][y1];
    bool flag = true;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (temp != paper[i][j])
            {
                flag = false;
            }
        }
        if (!flag)
        {
            break;
        }
    }

    if (flag)
    {
        if (temp == 0)
        {
            white++;
        }
        else if (temp == 1)
        {
            blue++;
        }
        result++;

        return result;
    }
    else
    {
        int new_x = (x1 + x2) / 2;
        int new_y = (y1 + y2) / 2;

        result +=
            square(x1, new_x, y1, new_y)
            + square(new_x + 1, x2, y1, new_y)
            + square(x1, new_x, new_y + 1, y2)
            + square(new_x + 1, x2, new_y + 1, y2);
    }

    return result;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }

    square(0, N - 1, 0, N - 1);
    cout << white << endl << blue << endl;


    return 0;
}