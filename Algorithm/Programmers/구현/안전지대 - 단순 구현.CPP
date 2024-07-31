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
#include <unordered_set>

using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int move_x[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
	int move_y[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

	bool temp_board[100][100];
	memset(temp_board, false, sizeof(temp_board));

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] == 1)
			{
				for (int dir = 0; dir < 9; ++dir)
				{
					int next_x = i + move_x[dir];
					int next_y = j + move_y[dir];

					if (next_x < 0 || next_x >= board.size() || next_y < 0 || next_y >= board.size())
					{
						continue;
					}
					temp_board[next_x][next_y] = true;
				}
			}
		}
	}

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (temp_board[i][j] == false)
			{
				answer++;
			}
		}
	}

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> board;

	board = {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
	};

	cout << solution(board);

	return 0;
}