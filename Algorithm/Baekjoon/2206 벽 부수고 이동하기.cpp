#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <memory.h>

using namespace std;

#define INF 999999999

typedef struct {
	int x, y;
	int cnt;
	bool flag;
} types;

int M, N, H; //가로 세로 높이
int box[1001][1001];
// 벽을 부순 visited와 벽을 부수지 않은 visited로 나눔
bool visited[1001][1001][2];
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };
int mini = INF;
queue<types> bfs;

void solution()
{
	while (!bfs.empty())
	{
		auto a = bfs.front();
		bfs.pop();

		if (a.x == N - 1 && a.y == M - 1)
		{
			if (mini > a.cnt)
			{
				mini = a.cnt;
				break;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = a.x + moveX[i];
			int ny = a.y + moveY[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (box[nx][ny] == 1 && a.flag == 0)
				{
					bfs.push({ nx, ny, a.cnt + 1, true });
					visited[nx][ny][a.flag + 1] = true;
				}
				else if (box[nx][ny] == 0 && !visited[nx][ny][a.flag])
				{
					bfs.push({ nx, ny, a.cnt + 1, a.flag });
					visited[nx][ny][a.flag] = true;
				}

			}


			/*if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && box[nx][ny] == 0)
			{
				bfs.push({ nx, ny, a.cnt + 1 });
				visited[nx][ny] = true;
			}*/
		}
	}
}

bool break_wall(int a, int b)
{
	if (box[a][b] == 0)
		return false;

	for (int i = 0; i < 4; i++)
	{
		int nx = a + moveX[i];
		int ny = b + moveY[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < M && box[nx][ny] == 0)
		{
			return true;
		}
	}
	return false;
}

int main(void)
{
	cin >> N >> M;

	memset(box, -1, sizeof(box));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &box[i][j]);

			//cin >> box[i][j];
		}
	}

	bfs.push({ 0, 0, 1, false });
	solution();

	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (break_wall(i, j))
			{
				memset(visited, false, sizeof(visited));
				bfs = queue<types>();
				bfs.push({ 0, 0, 1, false });

				box[i][j] = 0;
				solution();
				box[i][j] = 1;
			}
		}
	}*/

	if (mini == INF)
		cout << "-1" << '\n';
	else
		cout << mini << '\n';
}
