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

using namespace std;

int board[102];
bool visited[106];
typedef struct
{
    int n;
    int distance;
} types;
queue<types> bfs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int M;
    cin >> N >> M;

    for (int i = 0; i < N + M; i++)
    {
        int temp1;
        int temp2;
        cin >> temp1 >> temp2;

        board[temp1] = temp2;
    }

    bfs.push({ 1, 0 });
    visited[0] = true;
    visited[1] = true;

    vector<int> result;
    while (!bfs.empty())
    {
        auto current = bfs.front();
        bfs.pop();

        // cout << "current.n: " << current.n << " current.distance: " << current.distance << '\n';

        if (current.n == 100)
        {
            cout << current.distance << '\n';
            break;
        }

        for (int i = 1; i <= 6; i++)
        {
            int new_n = current.n + i;
            if (new_n > 100 || visited[new_n] == true)
            {
                continue;
            }
            visited[new_n] = true;

            if (board[new_n] == 0)
            {
                bfs.push({ new_n, current.distance + 1 });
            }
            else
            {
                bfs.push({ board[new_n], current.distance + 1 });
            }
        }
    }

    return 0;
}