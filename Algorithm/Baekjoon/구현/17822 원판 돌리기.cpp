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
    int x;
    int y;
}type;

queue<type> bfs;
int circles[51][51];
bool visited[51][51];
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, T;
    cin >> N >> M >> T;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> circles[i][j];
        }
    }

    while (T--)
    {
        // x 배수의 원판을 d의 방향으로 k번 회전
        int x, d, k;
        cin >> x >> d >> k;

        for (int i = x; i <= N; i += x)
        {
            // 이동 후 원판의 상태
            int temp_circle[51];
            for (int j = 0; j < M; ++j)
            {
                // 원판은 연결되어 있다는 것을 주의
                int move = k % M;
                int next;
                if (d == 0)
                {
                    next = j + move;
                }
                else
                {
                    next = j - move;
                }

                if (next >= M)
                {
                    next -= M;
                }
                if (next < 0)
                {
                    next += M;
                }

                temp_circle[next] = circles[i][j];
            }

            // 이동 후의 원판을 현재 원판에 덮어쓴다.
            copy(begin(temp_circle), end(temp_circle), begin(circles[i]));
        }

        // 삭제할 수를 넣어두는 vector
        vector<vector<type>> delete_nums;
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                // BFS로 현재 수와 인접하면서 같은 수를 탐색
                if (visited[i][j] == false && circles[i][j] != 0)
                {
                    // 현재 수와 같으면서 인접한 수의 위치를 벡터에 넣는다.
                    vector<type> delete_num;

                    bfs.push({ i, j });
                    visited[i][j] = true;

                    while (!bfs.empty())
                    {
                        type current = bfs.front();
                        bfs.pop();

                        delete_num.push_back(current);

                        for (int k = 0; k < 4; ++k)
                        {
                            int next_x = current.x + move_x[k];
                            int next_y = current.y + move_y[k];

                            // next_y는 원판이므로 처음과 끝도 인접하다.
                            if (next_y < 0)
                            {
                                next_y += M;
                            }
                            else if (next_y >= M)
                            {
                                next_y -= M;
                            }

                            if (next_x < 0 || next_x > N)
                            {
                                continue;
                            }

                            if (circles[next_x][next_y] == circles[i][j] && visited[next_x][next_y] == false)
                            {
                                bfs.push({ next_x, next_y });
                                visited[next_x][next_y] = true;
                            }
                        }
                    }

                    // 인접한 수가 있다면 delete_nums에 넣는다.
                    if (delete_num.size() >= 2)
                    {
                        delete_nums.push_back(delete_num);
                    }
                }
            }
        }

        memset(visited, false, sizeof(visited));

        // 인접한 수가 있다면 해당 수를 0으로 대입한다.
        if (!delete_nums.empty())
        {
            for (vector<type> delete_num : delete_nums)
            {
                for (type num : delete_num)
                {
                    circles[num.x][num.y] = 0;
                }
            }
        }
        else
        {
            // 인접한 수가 없을 경우 원판의 수의 평균을 구하고
            // 평균과 비교하여 수를 처리한다.
            int sum = 0;
            int count = 0;
            for (int i = 1; i <= N; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    if (circles[i][j] != 0)
                    {
                        sum += circles[i][j];
                        count++;
                    }
                }
            }
            float avg = (float)sum / count;

            for (int i = 1; i <= N; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    if (circles[i][j] != 0 && circles[i][j] != avg)
                    {
                        if (circles[i][j] > avg)
                        {
                            circles[i][j]--;
                        }
                        else
                        {
                            circles[i][j]++;
                        }
                    }
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            answer += circles[i][j];
        }
    }

    cout << answer;

    return 0;
}