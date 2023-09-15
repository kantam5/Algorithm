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
int M;
int arr[8];
int res[8];
bool visited[8];

void bfs(int current)
{
	if (current == M)
	{
		for (int i = 0; i < M; i++)
		{
			printf("%d ", res[i]);
		}
		printf("\n");

		return;
	}
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		if (!visited[i] && arr[i] != temp)
		{
			res[current] = arr[i];
			temp = res[current];
			visited[i] = true;
			bfs(current + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	bfs(0);

	return 0;
}