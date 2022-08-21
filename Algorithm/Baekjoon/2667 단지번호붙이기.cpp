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

bool visited[626];
int result_count = -1;
vector<int> result;
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
			result.push_back(0);
		}
		result[result_count]++;
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
		if (new_y < 0 || N <= new_y)
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
	scanf_s("%d", &N);

	vector<pair<int, int>> ground[26];

	int node_count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			scanf_s("%1d", &temp);

			if (temp == 1)
			{
				ground[i].push_back(make_pair(temp, node_count));
				node_count++;
			}
			else
			{
				ground[i].push_back(make_pair(temp, -1));
			}
		}
	}

	vector<int>* graph = new vector<int>[N * N + 1];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			create_graph(i, j, ground, graph);
		}
	}

	for (int i = 0; i < node_count; i++)
	{
		dfs(graph, i, i);
	}

	result_count++;
	cout << result_count << endl;

	sort(result.begin(), result.end());
	for (int i = 0; i < result_count; i++)
	{
		cout << result[i] << endl;
	}

	delete[] graph;

	return 0;
}