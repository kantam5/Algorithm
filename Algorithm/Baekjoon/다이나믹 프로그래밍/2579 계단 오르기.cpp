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

int cache[301];
int stair[301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> stair[i];
    }

    cache[0] = stair[0];
    cache[1] = max(stair[1], stair[1] + stair[0]);
    cache[2] = max(stair[2] + stair[0], stair[2] + stair[1]);

    
    for (int i = 3; i < N; i++)
    {
        cache[i] = max(stair[i] + cache[i - 2], stair[i] + stair[i - 1] + cache[i - 3]);
    }

    cout << cache[N - 1] << '\n';

    return 0;
}