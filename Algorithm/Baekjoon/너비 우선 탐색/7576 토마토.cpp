#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <memory.h>

using namespace std;

typedef struct {
	int x, y;
	int cnt;
} types;

int M, N, H; //가로 세로 높이
int box[1001][1001];
bool visited[1001][1001];
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };
queue<types> bfs;

int main(void) {
	int cnt = 0;

	scanf_s("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%d", &box[i][j]);

			if (box[i][j] == 1)
			{
				bfs.push({ i, j, 0 });
				visited[i][j] = true;
			}
			else if (box[i][j] == -1)
			{
				visited[i][j] = true;
			}
		}
	}


	if (bfs.empty())
	{
		printf("-1");
		return 0;
	}

	while (!bfs.empty())
	{
		auto a = bfs.front();
		bfs.pop();
		cnt = max(cnt, a.cnt);

		for (int i = 0; i < 4; i++)
		{
			int nx = a.x + moveX[i];
			int ny = a.y + moveY[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny])
			{
				bfs.push({ nx, ny, a.cnt + 1 });
				visited[nx][ny] = true;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j])
			{
				printf("-1");
				return 0;
			}
		}
	}

	printf("%d", cnt);
	return 0;

}