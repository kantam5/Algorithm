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

int dist[100'000];
int cost[100'000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> dist[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> cost[i];
    }

    int current = 0;
    long long answer = 0;

    // ���� �������� ������ �� ������ ������ ������ ���� �������� �⸧�� �����ϰ� �̵�, �̸� �ݺ�
    while (current < N)
    {
        int next = N;

        // ���� ������ ������ ���� �߿���, ���� ������ ���ݺ��� �⸧�� �� ������ �߰ߵǸ� ���� �������� �����Ѵ�.
        for (int i = current; i < N; ++i)
        {
            if (cost[current] > cost[i])
            {
                next = i;
                break;
            }
        }

        // ���� ���������� �Ÿ��� ����
        long long distance = 0;
        for (int i = current; i < next; ++i)
        {
            distance += dist[i];
        }

        // ���� �������� �ʿ��� �⸧�� ���� �������� ����
        answer += distance * cost[current];

        current = next;
    }

    cout << answer;

    return 0;
}
