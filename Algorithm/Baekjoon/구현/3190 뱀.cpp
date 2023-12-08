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

bool board[100][100];
bool snake[100][100];
char moves[100001];
// 북 동 남 서로 시계방향
int move_x[4] = { -1, 0, 1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < K; ++i)
    {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = true;
    }

    int L;
    cin >> L;
    for (int i = 0; i < L; ++i)
    {
        int time;
        char dir;
        cin >> time >> dir;
        moves[time] = dir;
    }

    int time = 0;                           // 답으로 출력할 시간
    int dir = 1;                            // 현재 뱀의 방향
    pair<int, int> head = make_pair(0, 0);  // 현재 머리의 위치
    pair<int, int> tail = make_pair(0, 0);  // 현재 꼬리의 위치
    queue<pair<int, int>> body;             // 사과를 먹지 못했을 때, 줄어들 꼬리의 위치가 front
    snake[0][0] = true;                     // 뱀이 있는 영역을 표시
    while (true)
    {
        time++;

        // 머리의 다음 위치를 계산
        head.first += move_x[dir];
        head.second += move_y[dir];

        // 벽에 부딪히거나, 뱀의 몸과 부딪혔을 때, while 종료
        if (head.first < 0 || head.first >= N || head.second < 0 || head.second >= N)
        {
            break;
        }
        if (snake[head.first][head.second])
        {
            break;
        }

        // 늘어난 머리의 위치를 true로 설정
        // queue에 늘어난 순서대로 머리의 위치를 넣는다.
        snake[head.first][head.second] = true;
        body.push(head);

        // 늘어난 머리 위치에 사과가 없을 경우
        if (!board[head.first][head.second])
        {
            // 꼬리의 위치를 false로 설정
            snake[tail.first][tail.second] = false;

            // 다음 꼬리의 위치를 queue에서 얻고, 설정한다.
            pair<int, int> next_tail = body.front();
            body.pop();
            tail.first = next_tail.first;
            tail.second = next_tail.second;
        }
        // 머리가 지나간 곳은 항상 false로 설정
        board[head.first][head.second] = false;

        // 뱀의 방향을 변경
        if (moves[time] == 'L')
        {
            dir = (dir + 3) % 4;
        }
        else if (moves[time] == 'D')
        {
            dir = (dir + 1) % 4;
        }
    }

    cout << time;

    return 0;
}
