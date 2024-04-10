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

int board[100][100] = { 0, };
int next_board[100][100] = { 0, };
bool visited[100][100] = { false, };
int move_x[4] = { 1, 0, -1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int cheese_count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 1)
			{
				cheese_count++;
			}
		}
	}

	copy(&board[0][0], &board[0][0] + 100 * 100, &next_board[0][0]);

	// cheese_count �� 0�� �� ������ �����Ѵ�.
	// ���� ������ cheese_count�� prev_cheese_count�� �����Ѵ�.
	int count = 0;
	int prev_cheese_count = 0;
	while (cheese_count > 0)
	{
		count++;
		prev_cheese_count = cheese_count;

		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));

		while (q.empty() == false)
		{
			int current_x = q.front().first;
			int current_y = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int next_x = current_x + move_x[dir];
				int next_y = current_y + move_y[dir];

				if (visited[next_x][next_y] == true ||
					next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
				{
					continue;
				}

				visited[next_x][next_y] = true;

				// ���� ĭ�� �� ĭ�̶�� ť�� �ִ´�. 
				// ġ���� cheese_count�� 1 �����ϰ�, ���� board�� �� ĭ���� ǥ���Ѵ�.
				if (board[next_x][next_y] == 0)
				{
					q.push(make_pair(next_x, next_y));
				}
				else if (board[next_x][next_y] == 1)
				{
					cheese_count--;
					next_board[next_x][next_y] = 0;
				}
			}
		}

		memset(visited, false, sizeof(visited));
		copy(&next_board[0][0], &next_board[0][0] + 100 * 100, &board[0][0]);
	}

	cout << count << '\n' << prev_cheese_count;

	return 0;
}