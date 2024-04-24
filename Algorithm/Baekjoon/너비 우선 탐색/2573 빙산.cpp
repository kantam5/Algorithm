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

int N, M;
int iceberg[300][300];
int next_iceberg[300][300];
bool visited[300][300];
int move_x[4] = { -1, 0, 1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

int CheckIcebergSplit()
{
	int icebergCount = 0;

	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < M; ++y)
		{
			// 현재 칸이 빙산이라면 bfs로 같은 빙산인 칸을 visited로 표시한다.
			if (iceberg[x][y] == 0 || visited[x][y] == true)
			{
				continue;
			}

			icebergCount++;

			queue<pair<int, int>> q;
			q.push(make_pair(x, y));

			while (q.empty() == false)
			{
				int current_x = q.front().first;
				int current_y = q.front().second;
				q.pop();

				for (int i = 0; i < 4; ++i)
				{
					int next_x = current_x + move_x[i];
					int next_y = current_y + move_y[i];

					if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M
						|| visited[next_x][next_y] == true
						|| iceberg[next_x][next_y] == 0)
					{
						continue;
					}

					q.push(make_pair(next_x, next_y));
					visited[next_x][next_y] = true;
				}
			}
		}
	}

	memset(visited, false, sizeof(visited));

	return icebergCount;
}

void MeltIceberg()
{
	copy(&iceberg[0][0], &iceberg[0][0] + 300 * 300, &next_iceberg[0][0]);

	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < M; ++y)
		{
			if (iceberg[x][y] != 0)
			{
				continue;
			}

			// 현재 칸이 0이라면 주위의 빙산을 녹인다.
			for (int i = 0; i < 4; ++i)
			{
				int next_x = x + move_x[i];
				int next_y = y + move_y[i];

				if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M
					|| iceberg[next_x][next_y] == 0
					|| next_iceberg[next_x][next_y] == 0)
				{
					continue;
				}

				next_iceberg[next_x][next_y]--;
			}
		}
	}

	copy(&next_iceberg[0][0], &next_iceberg[0][0] + 300 * 300, &iceberg[0][0]);
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
			cin >> iceberg[i][j];
		}
	}

	int answer = 0;
	while (true)
	{
		// 현재 빙산 조각의 수
		int iceburg_count = CheckIcebergSplit();
		if (iceburg_count == 0)
		{
			cout << 0;
			break;
		}
		else if (iceburg_count >= 2)
		{
			cout << answer;
			break;
		}

		answer++;
		MeltIceberg();
	}

	return 0;
}