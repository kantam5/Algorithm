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
// ������ ����� 0 �Ǵ� 1�� �׷������� �ִ� ��θ� ���ϴ� �˰���
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

        // ���� ������ �Һ�� ��� + �� ��带 ���ϴ� ����ġ < �� ������ ���µ� �Һ�� ���
        // ���ŵ� ����� ����� 0�̶�� ���� ó���� �ƴ϶�� ���� �Է�
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