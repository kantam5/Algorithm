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

    // �ü��� �� ĭ�� ���� �����ϴ� ������� ������ �����ϴ°� �� �����ϴ�.
    int archer_row = N;
    while (archer_row >= 1)
    {
        // �ü��� ������ Ÿ�ٵ�
        // Ÿ���� �ߺ��� �� �����Ƿ� set���� ����
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
                    // ���� �˻��ϴ� ĭ�� ���� ��츸 �Ÿ��� �˻��Ѵ�.
                    if (board[x][y] == 0)
                    {
                        continue;
                    }

                    int dist = abs(x - archer_row) + abs(y - current_archer_y);

                    // ���� �ü����� �����Ÿ��� D������ ���
                    if (dist <= D)
                    {
                        if (min_dist > dist)
                        {
                            current_target.first = x;
                            current_target.second = y;
                            min_dist = dist;
                        }
                        // �ּ� �Ÿ��� ���� �Ÿ��� ���ٸ� y���� �� ���� Ÿ���� �����Ѵ�.
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

            // ���� �ü��� Ÿ���� �ִٸ� set�� �ִ´�.
            if (current_target != pair<int, int>(-1, -1))
            {
                targets.insert(current_target);
            }
        }

        // ������ Ÿ�ٵ��� �����Ѵ�.
        for (pair<int, int> target : targets)
        {
            board[target.first][target.second] = 0;
            out++;
        }

        // �ü����� �� ĭ ���� �̵��Ѵ�.
        archer_row--;
    }

    return out;
}

// ��Ʈ��ŷ���� 3���� �ü��� ��ġ�Ѵ�.
void BackTracking(int index)
{
    // 3�� ��ġ�Ǿ��ٸ� ������ �����Ѵ�.
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