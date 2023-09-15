#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <memory.h>

using namespace std;

int M;
int N;

bool visited[2501];
int result_count = 0;
int node_temp = -1;
// current노드부터 시작하여 graph를 깊이 우선 탐색
void dfs(vector<int> graph[], int current, int n)
{
	if (!visited[current])
	{
		if (node_temp != n)
		{
			node_temp = n;
			result_count++;
		}
	}
	visited[current] = true;

	for (int next : graph[current])
	{
		if (!visited[next])
		{
			dfs(graph, next, n);
		}
	}
}

// 상하좌우로 1인 노드를 연결하여 그래프 생성
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
void create_graph(int y, int x, vector<pair<int, int>> ground[], vector<int> graph[])
{
	if (ground[y][x].first == 0)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		// new_y와 new_x가 N과 M의 범위를 초과한다면 continue
		int new_y = y + dy[i];
		int new_x = x + dx[i];
		if (new_y < 0 || M <= new_y)
		{
			continue;
		}
		if (new_x < 0 || N <= new_x)
		{
			continue;
		}

		if (ground[new_y][new_x].first == 1)
		{
			graph[ground[y][x].second].push_back(ground[new_y][new_x].second);
		}
	}

	return;
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int K;
		cin >> M >> N >> K;

		vector<pair<int, int>> ground[51];
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ground[i].push_back(make_pair(0, -1));
			}
		}

		int node_count = 0;
		for (int i = 0; i < K; i++)
		{
			int temp_y;
			int temp_x;
			cin >> temp_y >> temp_x;

			ground[temp_y][temp_x].first = 1;
			ground[temp_y][temp_x].second = node_count;
			node_count++;
		}

		vector<int>* graph = new vector<int>[K + 1];
		// cout << endl;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// cout << ground[i][j].first << " ";
				create_graph(i, j, ground, graph);
			}
			// cout << endl;
		}

		/*for (int i = 0; i < node_count; i++)
		{
			cout << i << ": ";
			for (int j = 0; j < graph[i].size(); j++)
			{
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}*/

		for (int i = 0; i < node_count; i++)
		{
			dfs(graph, i, i);
		}

		cout << result_count << endl;

		memset(visited, 0, sizeof(visited));
		result_count = 0;
		node_temp = -1;

		delete[] graph;
	}

	return 0;
}