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

vector<vector<int>> dist;
vector<vector<pair<int, int>>> edges;

void dijkstra(int start)
{
	dist[start][start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (pq.empty() == false)
	{
		pair<int, int> current = pq.top();
		pq.pop();

		int currentNode = current.second;
		int currentDist = current.first * (-1);

		if (dist[start][currentNode] < currentDist)
		{
			continue;
		}

		for (auto edge : edges[currentNode])
		{
			int nextNode = edge.first;
			int nextDist = currentDist + edge.second;

			if (dist[start][nextNode] > nextDist)
			{
				dist[start][nextNode] = nextDist;

				pq.push(make_pair((-1) * nextDist, nextNode));
			}
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
	dist.resize(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		dist[i].resize(n + 1, INT_MAX);
	}

	edges.resize(n + 1);
	for (int i = 0; i < fares.size(); ++i)
	{
		int firstNode = fares[i][0];
		int secondNode = fares[i][1];
		int dist = fares[i][2];

		edges[firstNode].push_back(make_pair(secondNode, dist));
		edges[secondNode].push_back(make_pair(firstNode, dist));
	}

	// 다익스트라는 s, a, b 세번만 실행
	dijkstra(s);
	dijkstra(a);
	dijkstra(b);

	// s -> i, i -> a, i -> b
	// 세 경로의 합의 최솟값
	int mini = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		int currentDist = dist[s][i] + dist[a][i] + dist[b][i];

		mini = min(mini, currentDist);
	}

	return mini;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> fares = {
		{4, 1, 10},
		{3, 5, 24},
		{5, 6, 2},
		{3, 1, 41},
		{5, 1, 24},
		{4, 6, 50},
		{2, 4, 66},
		{2, 3, 22},
		{1, 6, 25}
	};

	cout << solution(6, 4, 6, 2, fares);

	return 0;
}