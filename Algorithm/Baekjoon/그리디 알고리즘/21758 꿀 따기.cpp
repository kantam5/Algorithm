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

int sum[100001];
int honey[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> honey[i];
        sum[i] = sum[i - 1] + honey[i];
    }

    int answer = 0;

    // ������ ���� ���� ���� �� �ϳ��̴�.
    // ������ ��� ��򰡿� �ְ�, ���� �������� �����ϴ� ���
    // ������ 1, N �� �� �ϳ��� ��ġ�� �ְ�, �� ���� ������ �ݴ���, �� ���� ��� ��򰡿� ��ġ�ϴ� ���
    // ������ 1, N �� �� �ϳ��� ��ġ�� ���� ��, �� ���� ���� �ݴ��� �ִ°� ���� �����ϴ�.

    // �� - ���� - ��
    for (int hive = 2; hive < N; ++hive)
    {
        int current = (sum[hive] - honey[1]) + (sum[N - 1] - sum[hive - 1]);
        answer = max(answer, current);
    }

    // ���� - �� - ��
    for (int bee = 2; bee < N; ++bee)
    {
        int current = (sum[bee - 1]) + (sum[N - 1] - honey[bee]);
        answer = max(answer, current);
    }

    // �� - �� - ����
    for (int bee = 2; bee < N; ++bee)
    {
        int current = (sum[N] - sum[bee]) + (sum[N] - honey[1] - honey[bee]);
        answer = max(answer, current);
    }

    cout << answer;

    return 0;
}