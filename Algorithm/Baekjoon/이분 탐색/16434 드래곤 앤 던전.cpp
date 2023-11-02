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

typedef struct
{
    int t;
    int a;
    int h;
}room;

vector<room> rooms;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, ATK;
    cin >> N >> ATK;

    for (int i = 0; i < N; ++i)
    {
        int t, a, h;
        cin >> t >> a >> h;

        rooms.push_back({ t, a, h });
    }

    // 최대 체력의 최솟값은 1이며, 최대 체력은 LLONG_MAX - 1로 설정하였다.
    long long start = 1;
    long long end = LLONG_MAX - 1;
    long long answer = end;
    while (start <= end)
    {
        // mid는 현재 최대 체력
        long long mid = (start + end) / 2;

        // 용사의 status를 초기화한다.
        long long current_HP = mid;
        long long current_ATK = ATK;

        // flag가 true일 경우 던전 공략에 성공, false는 실패
        int flag = true;
        for (int i = 0; i < N; ++i)
        {
            room current_room = rooms[i];

            // 몬스터 방일 경우
            if (current_room.t == 1)
            {
                // 용사는 몬스터를 처치할 때까지 turn번 몬스터의 공격을 맞는다.
                // turn은 (몬스터의 체력 / 현재 공격력)이며, 나누어 떨어질 경우 1번 덜 맞는다.
                long long turn = current_room.h / current_ATK;
                if (current_room.h % current_ATK == 0)
                {
                    turn--;
                }

                // turn번 공격을 맞았을 때, 체력이 0이하라면 현재 mid 최대 체력으로는 부족하다.
                if (current_HP - (current_room.a * turn) <= 0)
                {
                    flag = false;
                    break;
                }
                else
                {
                    // turn번 공격을 맞았다.
                    current_HP -= (current_room.a * turn);
                }
            }
            // 아이템 방일 경우 용사의 공격력과 체력을 회복한다.
            else if (current_room.t == 2)
            {
                current_ATK += current_room.a;
                current_HP = min(mid, current_HP + current_room.h);
            }
        }

        // 공략에 성공한 경우 end를 줄여서 다시 검사한다.
        // 실패한 경우 start를 늘린다.
        if (flag)
        {
            answer = min(answer, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << answer;

    return 0;
}