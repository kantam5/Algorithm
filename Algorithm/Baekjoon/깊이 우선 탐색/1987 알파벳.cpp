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

int R, C;
char board[21][21];
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };
int answer = 0;

void dfs(int x, int y, int dist, vector<char> alphabets)
{
    answer = max(answer, dist);

    bool flag = false;
    for (int i = 0; i < 4; ++i)
    {
        int next_x = x + move_x[i];
        int next_y = y + move_y[i];
        if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C)
        {
            if (find(alphabets.begin(), alphabets.end(), board[next_x][next_y]) == alphabets.end())
            {
                alphabets.push_back(board[next_x][next_y]);

                dfs(next_x, next_y, dist + 1, alphabets);

                alphabets.pop_back();
            }
        }
    }

}

int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
        }
    }

    vector<char> v;
    v.push_back(board[0][0]);
    dfs(0, 0, 1, v);

    cout << answer;

    return 0;
}