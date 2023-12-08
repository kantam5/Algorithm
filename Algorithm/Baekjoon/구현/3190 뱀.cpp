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

bool board[100][100];
bool snake[100][100];
char moves[100001];
// �� �� �� ���� �ð����
int move_x[4] = { -1, 0, 1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < K; ++i)
    {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = true;
    }

    int L;
    cin >> L;
    for (int i = 0; i < L; ++i)
    {
        int time;
        char dir;
        cin >> time >> dir;
        moves[time] = dir;
    }

    int time = 0;                           // ������ ����� �ð�
    int dir = 1;                            // ���� ���� ����
    pair<int, int> head = make_pair(0, 0);  // ���� �Ӹ��� ��ġ
    pair<int, int> tail = make_pair(0, 0);  // ���� ������ ��ġ
    queue<pair<int, int>> body;             // ����� ���� ������ ��, �پ�� ������ ��ġ�� front
    snake[0][0] = true;                     // ���� �ִ� ������ ǥ��
    while (true)
    {
        time++;

        // �Ӹ��� ���� ��ġ�� ���
        head.first += move_x[dir];
        head.second += move_y[dir];

        // ���� �ε����ų�, ���� ���� �ε����� ��, while ����
        if (head.first < 0 || head.first >= N || head.second < 0 || head.second >= N)
        {
            break;
        }
        if (snake[head.first][head.second])
        {
            break;
        }

        // �þ �Ӹ��� ��ġ�� true�� ����
        // queue�� �þ ������� �Ӹ��� ��ġ�� �ִ´�.
        snake[head.first][head.second] = true;
        body.push(head);

        // �þ �Ӹ� ��ġ�� ����� ���� ���
        if (!board[head.first][head.second])
        {
            // ������ ��ġ�� false�� ����
            snake[tail.first][tail.second] = false;

            // ���� ������ ��ġ�� queue���� ���, �����Ѵ�.
            pair<int, int> next_tail = body.front();
            body.pop();
            tail.first = next_tail.first;
            tail.second = next_tail.second;
        }
        // �Ӹ��� ������ ���� �׻� false�� ����
        board[head.first][head.second] = false;

        // ���� ������ ����
        if (moves[time] == 'L')
        {
            dir = (dir + 3) % 4;
        }
        else if (moves[time] == 'D')
        {
            dir = (dir + 1) % 4;
        }
    }

    cout << time;

    return 0;
}
