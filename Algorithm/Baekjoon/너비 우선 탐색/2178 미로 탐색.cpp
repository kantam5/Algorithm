#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N;
int M;

queue<int> q;
bool visited[10001];
int edge_count = 0;
int _distance[10001];
void bfs(const vector<int> graph[], int source)    // source는 시작 노드
{
	// source 방문
	q.push(source);
	visited[source] = true;
	_distance[source] = 0;

	while (!q.empty())
	{

		int current = q.front();
		q.pop();

		// cout << "source: " << source << "  current: " << current << "  _distance[current]: " << _distance[current] << endl;

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
}

// 상하좌우로 1인 노드를 연결하여 그래프 생성
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
void create_graph(int y, int x, vector<pair<int, int>> maze[], vector<int> graph[])
{
	if (maze[y][x].first == 0)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int new_y = y + dy[i];
		int new_x = x + dx[i];
		if (new_y < 0 || N <= new_y)
		{
			continue;
		}
		if (new_x < 0 || M <= new_x)
		{
			continue;
		}

		if (maze[new_y][new_x].first == 1)
		{
			graph[maze[y][x].second].push_back(maze[new_y][new_x].second);
		}
	}

	return;
}

int main()
{
	cin >> N >> M;

	vector<pair<int, int>> maze[101];
	int node_count = 0;
	vector<int> graph[10001];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp;
			scanf_s("%1d", &temp);
			if (temp == 1)
			{
				maze[i].push_back(make_pair(temp, node_count));
				node_count++;
			}
			else
			{
				maze[i].push_back(make_pair(temp, -1));
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// cout << maze[i][j].first << " ";

			create_graph(i, j, maze, graph);
		}
		// cout << endl;
	}

	/*cout << endl;

	for (int i = 0; i < N * M; i++)
	{
		cout << i << ": ";
		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}*/

	bfs(graph, 0);
	cout << _distance[node_count - 1] + 1 << endl;

	return 0;
}