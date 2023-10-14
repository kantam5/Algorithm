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

bool cache[2001][2001];
int num[2001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, M;

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> num[i];
    }

    cin >> M;

    // S�� E�� ���ٸ� true
    for (int i = 1; i <= N; ++i)
    {
        cache[i][i] = true;
    }

    // E == S + 1�� ��� �� ���� ���ؼ� ���ٸ� true
    for (int i = 1; i < N; ++i)
    {
        if (num[i] == num[i + 1])
        {
            cache[i][i + 1] = true;
        }
    }

    while (M--)
    {
        int S;
        int E;
        cin >> S >> E;

        // �� ������ ���� �˻縦 ����
        // S������ ���� E������ ���� �����鼭 �� ������ ������ �Ӹ�����̸� S�� E������ ������ �Ӹ�����̴�.
        // ���� ����� ���ϸ鼭 �˻�
        int temp_start = S;
        int temp_end = E;
        while (temp_start <= temp_end)
        {
            if (num[temp_start] == num[temp_end] && cache[temp_start][temp_end] == 1)
            {
                cache[S][E] = true;
                break;
            }
            else if (num[temp_start] != num[temp_end])
            {
                cache[S][E] = false;
                break;
            }

            temp_start++;
            temp_end--;
        }

        cout << cache[S][E] << '\n';
    }

    return 0;
}