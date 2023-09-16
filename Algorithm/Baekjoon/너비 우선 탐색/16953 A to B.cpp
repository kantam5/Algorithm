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

unordered_map<long long, bool> visited;
typedef struct
{
    long long n;
    int distance;
} types;
queue<types> bfs;

void solution(long long a, long long b)
{
    bfs.push({ a, 1 });
    visited.insert(make_pair(a, true));

    while (!bfs.empty())
    {
        auto current = bfs.front();
        bfs.pop();

        // cout << "current.n: " << current.n << " current.distance: " << current.distance << '\n';

        if (current.n == b)
        {
            cout << current.distance << '\n';
            return;
        }

        if (current.n * 2 <= 1000000001 && visited.find(current.n * 2) == visited.end() && current.n <= b)
        {
            bfs.push({ current.n * 2, current.distance + 1 });
            visited.insert(make_pair(current.n * 2, true));
        }

        if (current.n * 10 + 1 <= 1000000001 && visited.find(current.n * 10 + 1) == visited.end() && current.n <= b)
        {
            bfs.push({ current.n * 10 + 1, current.distance + 1 });
            visited.insert(make_pair(current.n * 10 + 1, true));
        }
    }

    cout << "-1" << '\n';
    return;
}

int main()
{
    long long A;
    long long B;

    cin >> A >> B;

    solution(A, B);

    return 0;
}

// 다른 사람 꺼
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int mini = 10000; // 임의의 큰수
long long A, B, cnt;

void dfs(long long a, int cnt)
{
    if (a > B) return;

    if (a == B)
    {
        mini = min(mini, cnt);
    }
    dfs(a * 2, cnt + 1);
    dfs(a * 10 + 1, cnt + 1);

}

int main()
{
    cin >> A >> B;

    dfs(A, 1);

    if (mini == 10000) cout << -1;
    else cout << mini;
}