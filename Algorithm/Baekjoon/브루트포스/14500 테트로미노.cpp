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

int N;
int M;
int paper[501][501];

vector<vector<int>> dy
{
    {0, 0, 0, 0},
    {0, 1, 2, 3},

    {0, 0, 1, 1},

    {0, 1, 2, 2},
    {0, -1, -1, -1},
    {0, 0, 1, 2},
    {0, 0, 0, -1},
    {0, 0, -1, -2},
    {0, 1, 1, 1},
    {0, 0, 1, 2},
    {0, 0, 0, 1},

    {0, 1, 1, 2},
    {0, 0, -1, -1},
    {0, -1, -1, -2},
    {0, 0, 1, 1},

    {0, 0, 1, 0},
    {0, -1, 0, 1},
    {0, -1, 0, 0},
    {0, 1, 2, 1}
};
vector<vector<int>> dx
{
    {0, 1, 2, 3},
    {0, 0, 0, 0},

    {0, 1, 0, 1},

    {0, 0, 0, 1},
    {0, 0, 1, 2},
    {0, 1, 1, 1},
    {0, 1, 2, 2},
    {0, 1, 1, 1},
    {0, 0, 1, 2},
    {0, 1, 0, 0},
    {0, 1, 2, 2},

    {0, 0, 1, 1},
    {0, 1, 1, 2},
    {0, 0, 1, 1},
    {0, 1, 1, 2},

    {0, 1, 1, 2},
    {0, 1, 1, 1},
    {0, 1, 1, 2},
    {0, 0, 0, 1}
};

int solution(int y, int x)
{
    int result = 0;
    int temp;

    for (int i = 0; i < dy.size(); i++)
    {
        temp = 0;
        for (int j = 0; j < dy[i].size(); j++)
        {
            int new_y = y + dy[i][j];
            int new_x = x + dx[i][j];
            if (new_y < 0 || N <= new_y)
            {
                continue;
            }
            if (new_x < 0 || M <= new_x)
            {
                continue;
            }

            temp += paper[new_y][new_x];
            // cout << "y: " << y << "  x: " << x << "  new_y: " << new_y << "  new_x: " << new_x << "  paper[new_y][new_x]: " << paper[new_y][new_x] << "  temp: " << temp << '\n';
        }
        // cout << '\n';
        result = max(result, temp);
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> paper[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            result = max(result, solution(i, j));
        }
    }

    cout << result << '\n';

    return 0;
}