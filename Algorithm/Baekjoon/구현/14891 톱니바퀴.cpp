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

// 기어 회전
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
        int order_gear = order[i].first;
        int order_dir = order[i].second;

        // 현재 order에서 회전시킬 기어들
        vector<pair<int, int>> move_gear;
        move_gear.push_back(make_pair(order_gear, order_dir));

        // 현재 기어의 오른쪽 기어들 탐색
        for (int current_gear = order_gear + 1; current_gear < 4; ++current_gear)
        {
            // 현재 기어와 현재 기어 바로 왼쪽 기어의 상태를 비교
            if (gear[current_gear - 1][2] != gear[current_gear][6])
            {
                // 돌릴 방향은 현재 기어와의 위치에 따라 다르다.
                if ((order_gear + current_gear) % 2 == 0)
                {
                    move_gear.push_back(make_pair(current_gear, order_dir));
                }
                else
                {
                    move_gear.push_back(make_pair(current_gear, (-1) * order_dir));
                }
            }
            else
            {
                // 현재 기어가 돌아가지 않는다면 현재 기어 + 1번 기어도 돌아가지 않는다.
                break;
            }
        }

        // 현재 기어의 왼쪽 기어들 탐색
        for (int current_gear = order_gear - 1; current_gear >= 0; --current_gear)
        {
            // 현재 기어와 현재 기어 바로 오른쪽 기어의 상태를 비교
            if (gear[current_gear + 1][6] != gear[current_gear][2])
            {
                // 돌릴 방향은 현재 기어와의 위치에 따라 다르다.
                if ((order_gear + current_gear) % 2 == 0)
                {
                    move_gear.push_back(make_pair(current_gear, order_dir));
                }
                else
                {
                    move_gear.push_back(make_pair(current_gear, (-1) * order_dir));
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
