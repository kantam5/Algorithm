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
queue<types> bfs;
int result;

void solution(int n, int k)
{
    bfs.push({ n, 0 });
    visited[n] = true;

    while (!bfs.empty())
    {
        auto current = bfs.front();
        bfs.pop();
        result = max(result, current.distance);

        // cout << "current.n: " << current.n << " current.distance: " << current.distance << '\n';

        if (current.n == k)
        {
            cout << current.distance << '\n';
            break;
        }

        if (current.n > 1 && visited[current.n - 1] == false)
        {
            bfs.push({ current.n - 1, current.distance + 1 });
            visited[current.n - 1] = true;
        }
        if (current.n <= 100001 && visited[current.n + 1] == false && current.n <= k)
        {
            bfs.push({ current.n + 1, current.distance + 1 });
            visited[current.n + 1] = true;
        }
        if (2 * current.n <= 100001 && visited[2 * current.n] == false && current.n <= k)
        {
            bfs.push({ 2 * current.n, current.distance + 1 });
            visited[2 * current.n] = true;
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