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

// 이동 방향 8가지
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K;
vector<fireball> room[51][51];      // 이동 전의 방이며 파이어볼이 합쳐진 후의 방
vector<fireball> diff[51][51];      // 이동 후의 방

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
        // 방을 각각 확인하며 파이어볼이 있다면 이동한다. 
        // diff에 이동 결과를 넣는다.
        for (int x = 0; x < N; ++x)
        {
            for (int y = 0; y < N; ++y)
            {
                for (fireball& current : room[x][y])
                {
                    // 방향에 따른 파이어볼의 이동
                    // 속도가 방의 크기보다 클 수 있으니, mod연산을 사용한다.
                    int speed = current.speed % N;
                    int direction = current.direction;

                    int next_x = x + dx[direction] * speed;
                    int next_y = y + dy[direction] * speed;

                    // 범위를 초과했다면 범위에 맞게 조절한다.
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

                // 검사가 끝났다면 방을 비운다.
                room[x][y].clear();
            }
        }

        // 이동 후의 방을 각각 확인한다.
        // 파이어볼이 2개 이상이라면 합치고 1개라면 그대로 둔다.
        for (int x = 0; x < N; ++x)
        {
            for (int y = 0; y < N; ++y)
            {
                if (diff[x][y].size() >= 2)
                {
                    // 현재 방의 파이어볼을 합친다.
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
                    // 합친고 나눴을 때, 질량이 0을 초과한 경우만 다시 room에 삽입
                    if (mass > 0)
                    {
                        // 방향이 모두 홀수거나 짝수라면 true
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

                // 검사가 끝났다면 방을 비운다.
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