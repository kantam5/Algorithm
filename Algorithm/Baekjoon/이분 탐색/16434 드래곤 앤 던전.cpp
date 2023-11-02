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

    // �ִ� ü���� �ּڰ��� 1�̸�, �ִ� ü���� LLONG_MAX - 1�� �����Ͽ���.
    long long start = 1;
    long long end = LLONG_MAX - 1;
    long long answer = end;
    while (start <= end)
    {
        // mid�� ���� �ִ� ü��
        long long mid = (start + end) / 2;

        // ����� status�� �ʱ�ȭ�Ѵ�.
        long long current_HP = mid;
        long long current_ATK = ATK;

        // flag�� true�� ��� ���� ������ ����, false�� ����
        int flag = true;
        for (int i = 0; i < N; ++i)
        {
            room current_room = rooms[i];

            // ���� ���� ���
            if (current_room.t == 1)
            {
                // ���� ���͸� óġ�� ������ turn�� ������ ������ �´´�.
                // turn�� (������ ü�� / ���� ���ݷ�)�̸�, ������ ������ ��� 1�� �� �´´�.
                long long turn = current_room.h / current_ATK;
                if (current_room.h % current_ATK == 0)
                {
                    turn--;
                }

                // turn�� ������ �¾��� ��, ü���� 0���϶�� ���� mid �ִ� ü�����δ� �����ϴ�.
                if (current_HP - (current_room.a * turn) <= 0)
                {
                    flag = false;
                    break;
                }
                else
                {
                    // turn�� ������ �¾Ҵ�.
                    current_HP -= (current_room.a * turn);
                }
            }
            // ������ ���� ��� ����� ���ݷ°� ü���� ȸ���Ѵ�.
            else if (current_room.t == 2)
            {
                current_ATK += current_room.a;
                current_HP = min(mid, current_HP + current_room.h);
            }
        }

        // ������ ������ ��� end�� �ٿ��� �ٽ� �˻��Ѵ�.
        // ������ ��� start�� �ø���.
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