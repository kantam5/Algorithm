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

struct Shark
{
	int pos_x = -1;
	int pos_y = -1;
	int speed = -1;
	int dir = -1;
	int size = -1;
	bool alive = true;
};

int R, C, M;
int board[102][102];
int next_board[102][102];
vector<Shark> sharks;
int answer = 0;

int move_x[4] = { -1, 1, 0, 0 };
int move_y[4] = { 0, 0, 1, -1 };

void fishing(int person)
{
	// 현재 열에서 행이 0과 가장 가까운 위치의 상어를 잡는다.
	for (int x = 0; x < R; ++x)
	{
		if (board[x][person] != -1)
		{
			Shark* shark = &sharks[board[x][person]];
			answer += shark->size;

			board[x][person] = -1;

			shark->alive = false;

			break;
		}
	}
}

void move_sharks()
{
	for (int idx = 0; idx < sharks.size(); ++idx)
	{
		Shark* shark = &sharks[idx];

		if (shark->alive == false)
		{
			continue;
		}

		int next_x = shark->pos_x;
		int next_y = shark->pos_y;
		int speed = shark->speed;

		// 세로로 움직이는 경우
		if (shark->dir < 2)
		{
			speed %= ((R - 1) * 2);

			next_x += speed * move_x[shark->dir];

			// 움직인 다음 범위를 초과한 경우 조정
			if (next_x >= R)
			{
				next_x = (2 * R) - 2 - next_x;
				shark->dir = 0;

				if (next_x < 0)
				{
					next_x *= -1;
					shark->dir = 1;
				}
			}
			else if (next_x < 0)
			{
				next_x *= -1;
				shark->dir = 1;

				if (next_x >= R)
				{
					next_x = (2 * R) - 2 - next_x;
					shark->dir = 0;
				}
			}
		}
		// 가로로 움직이는 경우
		else
		{
			speed %= ((C - 1) * 2);

			next_y += speed * move_y[shark->dir];

			// 움직인 다음 범위를 초과한 경우 조정
			if (next_y >= C)
			{
				next_y = (2 * C) - 2 - next_y;
				shark->dir = 3;

				if (next_y < 0)
				{
					next_y *= -1;
					shark->dir = 2;
				}
			}
			else if (next_y < 0)
			{
				next_y *= -1;
				shark->dir = 2;

				if (next_y >= C)
				{
					next_y = (2 * C) - 2 - next_y;
					shark->dir = 3;
				}
			}

		}
		shark->pos_x = next_x;
		shark->pos_y = next_y;

		// 이동한 위치에 이미 상어가 위치해 있는 경우
		if (next_board[next_x][next_y] != -1)
		{
			Shark* prev_shark = &sharks[next_board[next_x][next_y]];

			// 이미 있는 상어와 크기를 비교한다.
			if (shark->size > prev_shark->size)
			{
				next_board[next_x][next_y] = idx;
				prev_shark->alive = false;
			}
			else
			{
				shark->alive = false;
			}
		}
		// 이동한 위치에 이미 상어가 위치해 있지 않은 경우
		else
		{
			next_board[next_x][next_y] = idx;
		}
	}

	copy(&next_board[0][0], &next_board[0][0] + 102 * 102, &board[0][0]);

	memset(next_board, -1, sizeof(next_board));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> M;

	memset(board, -1, sizeof(board));
	memset(next_board, -1, sizeof(board));

	for (int i = 0; i < M; ++i)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		sharks.push_back({ r - 1, c - 1, s, d - 1, z, true });

		board[r - 1][c - 1] = i;
	}

	for (int person = 0; person < C; ++person)
	{
		fishing(person);
		move_sharks();
	}

	cout << answer;

	return 0;
}