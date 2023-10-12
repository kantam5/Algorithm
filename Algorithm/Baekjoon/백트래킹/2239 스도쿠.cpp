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

int ground[9][9];
bool num_vertical[10][9];                   // �� ���� �Էµ� ��
bool num_horizontal[10][9];                 // �� ���� �Էµ� ��
bool num_block[10][3][3];                   // �� ���� �Էµ� ��

void Print()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << ground[i][j];
        }
        cout << endl;
    }
}

// current�� 1�� �������Ѽ� ���带 1ĭ�� �Űܼ� �˻��Ѵ�. 
void solution(int current)
{
    if (current == 81)
    {
        Print();
        exit(0);                            // ���α׷� �ٷ� ����
    }

    int current_x = (current) / 9;          // ���� �˻��ϴ� ������ ��
    int current_y = (current) % 9;          // ���� �˻��ϴ� ������ ��

    // ���� �˻��ϴ� ĭ�� 0�̶��
    if (ground[current_x][current_y] == 0)
    {
        for (int k = 1; k <= 9; ++k)
        {
            // ���� ĭ�� k�� �Էµ� �� �ִ��� �˻�
            if (!num_vertical[k][current_x] && !num_horizontal[k][current_y] && !num_block[k][current_x / 3][current_y / 3])
            {
                // ���� ĭ�� k�� �Է��ϰ� ����ĭ�� ���� ĭ �˻�
                ground[current_x][current_y] = k;
                num_vertical[k][current_x] = true;
                num_horizontal[k][current_y] = true;
                num_block[k][current_x / 3][current_y / 3] = true;

                solution(current + 1);

                // ����ĭ�� ���� ĭ �˻� �Ϸ� �� ��Ʈ��ŷ
                ground[current_x][current_y] = 0;
                num_vertical[k][current_x] = false;
                num_horizontal[k][current_y] = false;
                num_block[k][current_x / 3][current_y / 3] = false;
            }
        }
    }
    else
    {
        // ���� ĭ�� 0�� �ƴ϶�� ���� ĭ �˻�
        solution(current + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    for (int i = 0; i < 9; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 9; ++j)
        {
            ground[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            num_vertical[ground[i][j]][i] = true;
            num_horizontal[ground[i][j]][j] = true;
            num_block[ground[i][j]][i / 3][j / 3] = true;
        }
    }

    // 0��° ĭ ���� �˻�
    solution(0);

    return 0;
}