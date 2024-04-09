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

struct cctv
{
	int x;
	int y;
	bool dir[4] = { false, };
};

int N, M;
int room_origin[8][8] = { 0, };
int room[8][8] = { 0, };
vector<cctv> cctvs;
int cctv_count = 0;
int answer = INT_MAX;
int move_x[4] = { -1, 0, 1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

void calc()
{
	copy(&room_origin[0][0], &room_origin[0][0] + 8 * 8, &room[0][0]);

	for (cctv& c : cctvs)
	{
		// 현재 cctv가 감시할 수 있는 방향의 사각 지대를 없앤다.
		for (int i = 0; i < 4; ++i)
		{
			if (c.dir[i] == true)
			{
				int current_x = c.x;
				int current_y = c.y;

				while (room[current_x][current_y] != 6
					&& current_x >= 0 && current_x < N
					&& current_y >= 0 && current_y < M)
				{
					if (room[current_x][current_y] == 0)
					{
						room[current_x][current_y] = -1;
					}

					current_x += move_x[i];
					current_y += move_y[i];
				}
			}
		}
	}

	int invisible = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (room[i][j] == 0)
			{
				invisible++;
			}
		}
	}

	memset(room, 0, sizeof(room));

	answer = min(answer, invisible);
}

void dfs(int depth)
{
	// 모든 cctv의 방향이 설정되었다면 사각 지대 계산
	if (depth == cctv_count)
	{
		calc();

		return;
	}

	int prev_dir[4];
	copy(&cctvs[depth].dir[0], &cctvs[depth].dir[0] + 4, &prev_dir[0]);

	for (int dir = 0; dir < 4; ++dir)
	{
		bool temp_dir[4] = { false, };

		// cctv 회전
		for (int i = 0; i < 4; ++i)
		{
			temp_dir[(i + dir) % 4] = cctvs[depth].dir[i];
		}
		for (int i = 0; i < 4; ++i)
		{
			cctvs[depth].dir[i] = temp_dir[i];
		}

		dfs(depth + 1);

		// 회전하기 전의 방향으로 백트래킹
		for (int i = 0; i < 4; ++i)
		{
			cctvs[depth].dir[i] = prev_dir[i];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> room_origin[i][j];

			// cctv의 종류에 따라 카메라의 초기 방향을 설정하고 vector에 넣는다.
			if (room_origin[i][j] == 1)
			{
				cctvs.push_back({ i, j, {true, false, false, false} });
				cctv_count++;
			}
			else if (room_origin[i][j] == 2)
			{
				cctvs.push_back({ i, j, {false, true, false, true} });
				cctv_count++;
			}
			else if (room_origin[i][j] == 3)
			{
				cctvs.push_back({ i, j, {true, true, false, false} });
				cctv_count++;
			}
			else if (room_origin[i][j] == 4)
			{
				cctvs.push_back({ i, j, {true, true, true, false} });
				cctv_count++;
			}
			else if (room_origin[i][j] == 5)
			{
				cctvs.push_back({ i, j, {true, true, true, true} });
				cctv_count++;
			}
		}
	}

	dfs(0);

	cout << answer;

	return 0;
}