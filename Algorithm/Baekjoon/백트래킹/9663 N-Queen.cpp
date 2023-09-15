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

int N;
int board[15];
int result = 0;

bool check(int level)
{
	for (int i = 0; i < level; i++)
	{
		// board[i]의 값은 queen이 위치한 열을 의미한다. 
		// board[i] == board[levle]이라면 같은 열에 queen이 있다는 의미이다.
		// (i, board[i])가 (level, board[level])의 대각선이라면
		// abs(board[level] - board[i]) == level - i를 만족한다.
		if (board[i] == board[level] || abs(board[level] - board[i]) == level - i)
		{
			return false;
		}
	}

	return true;
}

void nqueen(int current)
{
	if (current == N)
	{
		result++;
	}
	else
	{
		// 0부터 N까지 놓을 수 있는 queen의 열을 하나씩 놓아보면서
		// check(current)를 통해 0부터 current의 행까지 비교해본다. 
		for (int i = 0; i < N; i++)
		{
			board[current] = i;
			if (check(current))
			{
				nqueen(current + 1);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	nqueen(0);

	cout << result << '\n';

	return 0;
}



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

int N;
bool board[15][15];
bool board_temp[15][15];
bool possible[15][15];
int result = 0;

void printBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == true)
			{
				cout << 1 << " ";
			}
			else
			{
				cout << 0 << " ";
			}
		}
		cout << '\n';
	}
	cout << '\n';
}

void initBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = true;
		}
	}
}

void invertBoard(int x, int y)
{
	for (int i = 0; i < N; i++)
	{
		board[x][i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		board[i][y] = false;
	}

	int dx[4] = { -1, -1, 1, 1 };
	int dy[4] = { -1, 1, -1, 1 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; ; j++)
		{
			int new_x = x + j * dx[i];
			int new_y = y + j * dy[i];
			if (new_x < 0 || N <= new_x)
			{
				break;
			}
			if (new_y < 0 || N <= new_y)
			{
				break;
			}
			board[new_x][new_y] = false;
		}
	}
}

void setQueen(int current)
{
	if (current == N)
	{
		result++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == true)
			{
				copy(&board[0][0], &board[0][0] + 15 * 15, &board_temp[0][0]);
				invertBoard(i, j);

				// invertboard넣고 board_temp는 따로 저장하고 백트래킹 때 다시 전환
				// printBoard();
				setQueen(current + 1);

				copy(&board_temp[0][0], &board_temp[0][0] + 15 * 15, &board[0][0]);
				// printBoard();
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = true;
			board_temp[i][j] = true;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == true)
			{
				invertBoard(i, j);

				// invertboard넣고 board_temp는 따로 저장하고 백트래킹 때 다시 전환
				// printBoard();
				setQueen(1);

				initBoard();
				// printBoard();
			}
		}
	}

	cout << result << '\n';

	return 0;
}