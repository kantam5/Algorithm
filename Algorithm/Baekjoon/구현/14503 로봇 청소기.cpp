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

int room[50][50];
// ��, ��, ��, ��
int move_x[4] = { -1, 0, 1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> room[i][j];
        }
    }

    int answer = 0;
    while (true)
    {
        // ���� ĭ�� û������ ���� ĭ�� ��� û��
        if (room[r][c] == 0)
        {
            room[r][c] = -1;
            answer++;
        }

        // �����¿�� û�� ������ ĭ�� �ִ��� Ȯ��
        int flag = false;
        for (int i = 0; i < 4; ++i)
        {
            int next_x = r + move_x[i];
            int next_y = c + move_y[i];
            if (room[next_x][next_y] == 0)
            {
                flag = true;
                break;
            }
        }

        // û�Ұ����� ĭ�� �ִٸ�
        if (flag)
        {
            // �ݽð� �������� ȸ��
            d = (d + 3) % 4;
            int next_x = r + move_x[d];
            int next_y = c + move_y[d];
            if (room[next_x][next_y] == 0)
            {
                r = next_x;
                c = next_y;
            }
        }
        else
        {
            // ���� ���⿡�� ������ ��ġ
            int back_x = r - move_x[d];
            int back_y = c - move_y[d];
            if (room[back_x][back_y] != 1)
            {
                r = back_x;
                c = back_y;
            }
            else
            {
                // ������ ��ġ�� ���� ��� û�� ����
                break;
            }
        }
    }

    cout << answer;

    return 0;
}