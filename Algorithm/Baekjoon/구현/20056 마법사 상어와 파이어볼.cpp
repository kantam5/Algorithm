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

typedef struct {
    int mass;
    int speed;
    int direction;
}fireball;

// �̵� ���� 8����
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K;
vector<fireball> room[51][51];      // �̵� ���� ���̸� ���̾�� ������ ���� ��
vector<fireball> diff[51][51];      // �̵� ���� ��

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < M; ++i)
    {
        int r, c;
        fireball temp;
        cin >> r >> c >> temp.mass >> temp.speed >> temp.direction;

        room[r - 1][c - 1].push_back(temp);
    }

    while (K--)
    {
        // ���� ���� Ȯ���ϸ� ���̾�� �ִٸ� �̵��Ѵ�. 
        // diff�� �̵� ����� �ִ´�.
        for (int x = 0; x < N; ++x)
        {
            for (int y = 0; y < N; ++y)
            {
                for (fireball& current : room[x][y])
                {
                    // ���⿡ ���� ���̾�� �̵�
                    // �ӵ��� ���� ũ�⺸�� Ŭ �� ������, mod������ ����Ѵ�.
                    int speed = current.speed % N;
                    int direction = current.direction;

                    int next_x = x + dx[direction] * speed;
                    int next_y = y + dy[direction] * speed;

                    // ������ �ʰ��ߴٸ� ������ �°� �����Ѵ�.
                    if (next_x >= N)
                    {
                        next_x -= N;
                    }
                    if (next_x < 0)
                    {
                        next_x += N;
                    }
                    if (next_y >= N)
                    {
                        next_y -= N;
                    }
                    if (next_y < 0)
                    {
                        next_y += N;
                    }

                    diff[next_x][next_y].push_back(fireball(current));
                }

                // �˻簡 �����ٸ� ���� ����.
                room[x][y].clear();
            }
        }

        // �̵� ���� ���� ���� Ȯ���Ѵ�.
        // ���̾�� 2�� �̻��̶�� ��ġ�� 1����� �״�� �д�.
        for (int x = 0; x < N; ++x)
        {
            for (int y = 0; y < N; ++y)
            {
                if (diff[x][y].size() >= 2)
                {
                    // ���� ���� ���̾�� ��ģ��.
                    int mass = diff[x][y][0].mass;
                    int speed = diff[x][y][0].speed;
                    int prev_mod = diff[x][y][0].direction % 2;
                    bool flag = true;
                    for (int current = 1; current < diff[x][y].size(); ++current)
                    {
                        mass += diff[x][y][current].mass;
                        speed += diff[x][y][current].speed;
                        if (prev_mod != diff[x][y][current].direction % 2)
                        {
                            flag = false;
                        }
                    }

                    mass /= 5;
                    speed /= diff[x][y].size();
                    // ��ģ�� ������ ��, ������ 0�� �ʰ��� ��츸 �ٽ� room�� ����
                    if (mass > 0)
                    {
                        // ������ ��� Ȧ���ų� ¦����� true
                        if (flag)
                        {
                            room[x][y].push_back({ mass, speed, 0 });
                            room[x][y].push_back({ mass, speed, 2 });
                            room[x][y].push_back({ mass, speed, 4 });
                            room[x][y].push_back({ mass, speed, 6 });
                        }
                        else
                        {
                            room[x][y].push_back({ mass, speed, 1 });
                            room[x][y].push_back({ mass, speed, 3 });
                            room[x][y].push_back({ mass, speed, 5 });
                            room[x][y].push_back({ mass, speed, 7 });
                        }
                    }
                }
                else if (diff[x][y].size() == 1)
                {
                    room[x][y].push_back(fireball(diff[x][y][0]));
                }

                // �˻簡 �����ٸ� ���� ����.
                diff[x][y].clear();
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (fireball& current : room[i][j])
            {
                answer += current.mass;
            }
        }
    }

    cout << answer;

    return 0;
}