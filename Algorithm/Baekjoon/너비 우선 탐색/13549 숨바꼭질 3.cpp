#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <memory.h>
#include <unordered_map>

using namespace std;

bool visited[100001];
typedef struct
{
    int n;
    int distance;
} types;
deque<types> bfs;
int result;

// 0-1 bfs
// 간선의 비용이 0 또는 1인 그래프에서 최단 경로를 구하는 알고리즘
void solution(int n, int k)
{
    bfs.push_back({ n, 0 });
    visited[n] = true;

    while (!bfs.empty())
    {
        auto current = bfs.front();
        bfs.pop_front();
        result = max(result, current.distance);

        // cout << "current.n: " << current.n << " current.distance: " << current.distance << '\n';

        if (current.n == k)
        {
            cout << current.distance << '\n';
            break;
        }

        // 현재 노드까지 소비된 비용 + 그 노드를 향하는 가중치 < 그 노드까지 가는데 소비된 비용
        // 갱신된 노드의 비용이 0이라면 덱의 처음에 아니라면 끝에 입력
        if (2 * current.n <= 100001 && visited[2 * current.n] == false && current.n <= k)
        {
            bfs.push_front({ 2 * current.n, current.distance });
            visited[2 * current.n] = true;
        }
        if (current.n > 1 && visited[current.n - 1] == false)
        {
            bfs.push_back({ current.n - 1, current.distance + 1 });
            visited[current.n - 1] = true;
        }
        if (current.n <= 100001 && visited[current.n + 1] == false && current.n <= k)
        {
            bfs.push_back({ current.n + 1, current.distance + 1 });
            visited[current.n + 1] = true;
        }
    }
}

int main()
{
    int N;
    int K;

    cin >> N >> K;

    if (K == 0)
    {
        cout << N << '\n';
        return 0;
    }

    solution(N, K);

    return 0;
}