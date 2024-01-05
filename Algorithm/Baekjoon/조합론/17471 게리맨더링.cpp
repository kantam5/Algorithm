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

using namespace std;

int N;
int population[11];
bool selected[11];
bool edge[11][11];
bool visited[11];
int answer = INT_MAX;

// group�� ������ ���ǰ� �´��� Ȯ��
bool bfs(vector<int> group, bool state)
{
    memset(visited, false, sizeof(visited));
    visited[group[0]] = true;

    queue<int> q;
    q.push(group[0]);

    int count = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            // i�� current�� ���� state���� �Ѵ�.
            // i�� current�� �̾��� �־�� �Ѵ�.
            // �湮�� ���ű��� �ٽ� �湮���� �ʴ´�.
            if (selected[i] == state && edge[current][i] == true && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
                count++;
            }
        }
    }

    // ���ǿ� �°� �湮�� ���ű��� ���� group�� ���� �´ٸ� ��� ����� �����̴�.
    if (group.size() == count)
    {
        return true;
    }

    return false;
}

// A�� B������ �α����� ���
void calculate()
{
    int A = 0;
    int B = 0;

    for (int i = 1; i <= N; i++)
    {
        if (selected[i] == true)
        {
            A += population[i];
        }
        else
        {
            B += population[i];
        }
    }

    int result = abs(A - B);

    answer = min(answer, result);
}

// A�� B������ ������ ���ǰ� �´��� Ȯ��
bool check()
{
    vector<int> A;
    vector<int> B;

    for (int i = 1; i <= N; i++)
    {
        if (selected[i] == true)
        {
            A.push_back(i);
        }
        else
        {
            B.push_back(i);
        }
    }

    if (A.size() == 0 || B.size() == 0)
    {
        return false;
    }

    // A�� B��� ������ �����ؾ� �Ѵ�.
    if (bfs(A, true) != true)
    {
        return false;
    }
    if (bfs(B, false) != true)
    {
        return false;
    }

    return true;
}

void dfs(int x, int count)
{
    // ������ 1�� �̻��� ���ű��� ������.
    if (count >= 1)
    {
        if (check() == true)
        {
            calculate();
        }
    }

    for (int i = x; i <= N; i++)
    {
        if (selected[i] == true)
        {
            continue;
        }

        // i�� ����, ������ �ݺ��ϸ鼭 ��� ����� ���� üũ
        selected[i] = true;
        dfs(i, count + 1);
        selected[i] = false;
    }
}
int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> population[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int count;
        cin >> count;

        for (int j = 0; j < count; j++)
        {
            int dest;
            cin >> dest;

            edge[i][dest] = true;
            edge[dest][i] = true;
        }
    }

    dfs(1, 0);

    if (answer == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }

    return 0;
}
