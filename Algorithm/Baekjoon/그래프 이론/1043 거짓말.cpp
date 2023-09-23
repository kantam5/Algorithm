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

using namespace std;

vector<int> knowns;
vector<int> parties[51];
int parent[51];

int getParent(int n)
{
    if (parent[n] == n)
    {
        return n;
    }

    return getParent(parent[n]);
}

void Union(int n1, int n2)
{
    n1 = getParent(n1);
    n2 = getParent(n2);

    parent[n1] = n2;
}

int main()
{
    int N;
    int M;
    int knowns_num;
    int answer;

    cin >> N >> M;

    cin >> knowns_num;
    for (int i = 0; i < knowns_num; ++i)
    {
        int temp;
        cin >> temp;
        knowns.push_back(temp);
    }

    for (int i = 0; i < N; ++i)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; ++i)
    {
        int num;
        cin >> num;

        int prev;
        int current;
        for (int j = 0; j < num; ++j)
        {
            if (j < 1)
            {
                cin >> current;
            }
            else
            {
                prev = current;
                cin >> current;
                Union(prev, current);
            }

            parties[i].push_back(current);
        }
    }

    answer = M;
    for (vector<int> party : parties)
    {
        bool flag = false;
        for (int person : party)
        {
            if (flag)
            {
                break;
            }

            for (int known : knowns)
            {
                if (getParent(person) == getParent(known))
                {
                    flag = true;
                    break;
                }
            }
        }

        if (flag)
        {
            answer--;
        }
    }

    cout << answer;

    return 0;
}

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

using namespace std;

vector<int> graph[51];
vector<int> parties[51];
bool visited[51];
queue<int> q;

int main()
{
    int N;
    int M;
    int knowns_num;
    int answer;

    cin >> N >> M;
    cin >> knowns_num;

    for (int i = 0; i < knowns_num; ++i)
    {
        int known;
        cin >> known;
        graph[0].push_back(known);
    }

    for (int i = 0; i < M; ++i)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j)
        {
            int temp;
            cin >> temp;
            parties[i].push_back(temp);
        }
    }

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < parties[i].size(); ++j)
        {
            for (int k = 0; k < parties[i].size(); ++k)
            {
                if (j == k)
                {
                    continue;
                }

                graph[parties[i][j]].push_back(parties[i][k]);
            }
        }
    }

    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); ++i)
        {
            int next = graph[current][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }

    answer = M;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < parties[i].size(); ++j)
        {
            int node = parties[i][j];
            if (visited[node])
            {
                answer--;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}