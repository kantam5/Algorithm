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

int N, M, D;
int origin_board[16][16];
int board[16][16];
vector<int> archers;
int answer = 0;

int runGame()
{
    int out = 0;
    memcpy(board, origin_board, sizeof(origin_board));

    // 궁수가 한 칸씩 위로 전진하는 방식으로 게임을 진행하는게 더 간단하다.
    int archer_row = N;
    while (archer_row >= 1)
    {
        // 궁수가 선택한 타겟들
        // 타겟은 중복할 수 없으므로 set으로 설정
        set<pair<int, int>> targets;

        for (int i = 0; i < 3; ++i)
        {
            int current_archer_y = archers[i];
            int min_dist = INT_MAX;
            pair<int, int> current_target(-1, -1);

            for (int x = 0; x < archer_row; ++x)
            {
                for (int y = 0; y < M; ++y)
                {
                    // 현재 검사하는 칸이 적일 경우만 거리를 검사한다.
                    if (board[x][y] == 0)
                    {
                        continue;
                    }

                    int dist = abs(x - archer_row) + abs(y - current_archer_y);

                    // 현재 궁수와의 사정거리가 D이하일 경우
                    if (dist <= D)
                    {
                        if (min_dist > dist)
                        {
                            current_target.first = x;
                            current_target.second = y;
                            min_dist = dist;
                        }
                        // 최소 거리와 현재 거리가 같다면 y값이 더 작은 타겟을 선택한다.
                        else if (min_dist == dist)
                        {
                            if (current_target.second > y)
                            {
                                current_target.first = x;
                                current_target.second = y;
                                min_dist = dist;
                            }
                        }
                    }
                }
            }

            // 현재 궁수가 타겟이 있다면 set에 넣는다.
            if (current_target != pair<int, int>(-1, -1))
            {
                targets.insert(current_target);
            }
        }

        // 선택한 타겟들을 공격한다.
        for (pair<int, int> target : targets)
        {
            board[target.first][target.second] = 0;
            out++;
        }

        // 궁수줄을 한 칸 위로 이동한다.
        archer_row--;
    }

    return out;
}

// 백트래킹으로 3명의 궁수를 배치한다.
void BackTracking(int index)
{
    // 3명 배치되었다면 게임을 시작한다.
    if (archers.size() == 3)
    {
        answer = max(answer, runGame());

        return;
    }

    for (int i = index + 1; i < M; ++i)
    {
        archers.push_back(i);
        BackTracking(i);
        archers.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M >> D;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> origin_board[i][j];
        }
    }

    for (int i = 0; i < M; ++i)
    {
        archers.push_back(i);
        BackTracking(i);
        archers.pop_back();
    }

    cout << answer;

    return 0;
}