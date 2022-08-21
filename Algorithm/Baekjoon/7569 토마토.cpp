#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <memory.h>

using namespace std;

int N;
int M;
int H;

vector<int> result;

queue<int> q;
bool visited[1000001];
int edge_count = 0;
int _distance[1000001];	// soruce부터의 거리
void bfs(const vector<int> graph[], int source)    // source는 시작 노드
{
	// source 방문
	q.push(source);
	visited[source] = true;
	_distance[source] = 0;

	int temp;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		// cout << "source: " << source << "  current: " << current << "  _distance[current]: " << _distance[current] << endl;
		temp = _distance[current];

		for (int next : graph[current])
		{
			if (!visited[next])
			{
				edge_count++;
				q.push(next);
				visited[next] = true;
				_distance[next] = _distance[current] + 1;
			}
		}
	}
	result.push_back(temp);
}

// 상하좌우로 1인 노드를 연결하여 그래프 생성
int dy[6] = { -1, 0, 1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int dx[6] = { 0, 1, 0, -1, 0, 0 };
void create_graph(int y, int z, int x, vector<pair<int, int>> box[][101], vector<int> graph[])
{
	// maze에 입력된 값이 0이라면 넘긴다.
	if (box[y][z][x].first == -1)
	{
		return;
	}

	for (int i = 0; i < 6; i++)
	{
		// new_y와 new_x가 N과 M의 범위를 초과한다면 continue
		int new_y = y + dy[i];
		int new_z = z + dz[i];
		int new_x = x + dx[i];
		if (new_y < 0 || N <= new_y)
		{
			continue;
		}
		if (new_z < 0 || H <= new_z)
		{
			continue;
		}
		if (new_x < 0 || M <= new_x)
		{
			continue;
		}

		// 상하좌우로 maze의 값이 1인 노드를 그래프에 입력
		if (box[new_y][new_z][new_x].first == 1 || box[new_y][new_z][new_x].first == 0)
		{
			graph[box[y][z][x].second].push_back(box[new_y][new_z][new_x].second);
		}
	}

	return;
}

int main()
{
	scanf_s("%d %d %d", &M, &N, &H);

	// 가운데가 높이
	vector<pair<int, int>> box[101][101];
	vector<int> ripe;

	int node_count = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				int temp;
				scanf_s("%d", &temp);

				if (temp == 0 || temp == 1)
				{
					box[j][i].push_back(make_pair(temp, node_count));
					if (temp == 1)
					{
						ripe.push_back(node_count);
					}
					node_count++;
				}
				else
				{
					box[j][i].push_back(make_pair(temp, -1));
				}
			}
		}
	}

	bool flag = true;
	vector<int>* graph = new vector<int>[N * M * H + 1];
	// vector<int>* graph = new vector<int>(N * M * H);
	// vector<int> graph[100];
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				create_graph(j, i, k, box, graph);
				if (box[j][i][k].first == 0)
				{
					flag = false;
				}
			}
		}
	}

	if (flag)
	{
		printf("0\n");
		delete[] graph;
		return 0;
	}

	for (int i = 0; i < ripe.size(); i++)
	{
		bfs(graph, ripe[i]);
		memset(visited, 0, sizeof(visited));
		memset(_distance, 0, sizeof(_distance));
		edge_count = 0;
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < ripe.size(); i++)
	{
		bfs(graph, ripe[i]);
	}
	for (int i = 0; i < node_count; i++)
	{
		if (visited[i] == false)
		{
			printf("-1\n");
			delete[] graph;
			return 0;
		}
	}

	printf("%d\n", result[0]);

	delete[] graph;

	return 0;
}

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
	int x, y, z;
	int cnt;
} types;

int M, N, H; //가로 세로 높이
int box[101][101][101];
bool visited[101][101][101];
int moveX[6] = { 1, -1, 0, 0, 0, 0 };
int moveY[6] = { 0, 0, 1, -1, 0, 0 };
int moveZ[6] = { 0, 0, 0, 0, 1, -1 };
queue<types> bfs;

int main(void) {
	int cnt = 0;

	scanf("%d %d %d", &M, &N, &H);
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &box[i][j][k]);

				if (box[i][j][k] == 1)
				{
					bfs.push({ i, j, k, 0 });
					visited[i][j][k] = true;
				}
				else if (box[i][j][k] == -1)
				{
					visited[i][j][k] = true;
				}
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

		for (int i = 0; i < 6; i++)
		{
			int nx = a.x + moveX[i];
			int ny = a.y + moveY[i];
			int nz = a.z + moveZ[i];

			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < N && ny < M && nz < H && !visited[nx][ny][nz])
			{
				bfs.push({ nx, ny, nz, a.cnt + 1 });
				visited[nx][ny][nz] = true;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < H; k++)
			{
				if (!visited[i][j][k])
				{
					printf("-1");
					return 0;
				}
			}
		}
	}

	printf("%d", cnt);
	return 0;

}