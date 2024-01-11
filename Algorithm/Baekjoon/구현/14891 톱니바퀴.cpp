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

int gear[4][8];
pair<int, int> order[100];

// ��� ȸ��
void rotateGear(int num, int dir)
{
    if (dir == 1)
    {
        int temp = gear[num][7];
        for (int i = 7; i > 0; --i)
        {
            gear[num][i] = gear[num][i - 1];
        }
        gear[num][0] = temp;
    }
    else
    {
        int temp = gear[num][0];
        for (int i = 0; i < 7; ++i)
        {
            gear[num][i] = gear[num][i + 1];
        }
        gear[num][7] = temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;

    for (int i = 0; i < 4; ++i)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < 8; ++j)
        {
            gear[i][j] = temp[j] - '0';
        }
    }

    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        cin >> order[i].first >> order[i].second;
        order[i].first--;
    }

    for (int i = 0; i < K; ++i)
    {
        int current_gear = order[i].first;
        int current_dir = order[i].second;

        // ���� order���� ȸ����ų ����
        vector<pair<int, int>> move_gear;
        move_gear.push_back(make_pair(current_gear, current_dir));

        // ���� ����� ������ ���� Ž��
        for (int j = current_gear + 1; j < 4; ++j)
        {
            // j�� ���� j �ٷ� ���� ����� ���¸� ��
            if (gear[j - 1][2] != gear[j][6])
            {
                // ���� ������ ���� ������ ��ġ�� ���� �ٸ���.
                if ((current_gear + j) % 2 == 0)
                {
                    move_gear.push_back(make_pair(j, current_dir));
                }
                else
                {
                    move_gear.push_back(make_pair(j, (-1) * current_dir));
                }
            }
            else
            {
                // j�� �� ���ư��� �ʴ´ٸ� j + 1�� �� ���ư��� �ʴ´�.
                break;
            }
        }

        // ���� ����� ���� ���� Ž��
        for (int j = current_gear - 1; j >= 0; --j)
        {
            // j�� ���� j �ٷ� ������ ����� ���¸� ��
            if (gear[j + 1][6] != gear[j][2])
            {
                // ���� ������ ���� ������ ��ġ�� ���� �ٸ���.
                if ((current_gear + j) % 2 == 0)
                {
                    move_gear.push_back(make_pair(j, current_dir));
                }
                else
                {
                    move_gear.push_back(make_pair(j, (-1) * current_dir));
                }
            }
            else
            {
                break;
            }
        }

        for (int j = 0; j < move_gear.size(); ++j)
        {
            rotateGear(move_gear[j].first, move_gear[j].second);
        }
    }

    int answer = 0;
    int temp = 1;
    for (int i = 0; i < 4; ++i)
    {
        answer += gear[i][0] * temp;
        temp *= 2;
    }

    cout << answer;

    return 0;
}
