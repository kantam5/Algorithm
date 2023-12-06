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

int room[50][50];
// 북, 동, 남, 서
int move_x[4] = { -1, 0, 1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> room[i][j];
        }
    }

    int answer = 0;
    while (true)
    {
        // 현재 칸이 청소하지 않은 칸인 경우 청소
        if (room[r][c] == 0)
        {
            room[r][c] = -1;
            answer++;
        }

        // 상하좌우로 청소 가능한 칸이 있는지 확인
        int flag = false;
        for (int i = 0; i < 4; ++i)
        {
            int next_x = r + move_x[i];
            int next_y = c + move_y[i];
            if (room[next_x][next_y] == 0)
            {
                flag = true;
                break;
            }
        }

        // 청소가능한 칸이 있다면
        if (flag)
        {
            // 반시계 방향으로 회전
            d = (d + 3) % 4;
            int next_x = r + move_x[d];
            int next_y = c + move_y[d];
            if (room[next_x][next_y] == 0)
            {
                r = next_x;
                c = next_y;
            }
        }
        else
        {
            // 현재 방향에서 후진한 위치
            int back_x = r - move_x[d];
            int back_y = c - move_y[d];
            if (room[back_x][back_y] != 1)
            {
                r = back_x;
                c = back_y;
            }
            else
            {
                // 후진한 위치가 벽인 경우 청소 종료
                break;
            }
        }
    }

    cout << answer;

    return 0;
}