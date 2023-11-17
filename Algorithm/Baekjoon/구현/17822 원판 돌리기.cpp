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
        // x ����� ������ d�� �������� k�� ȸ��
        int x, d, k;
        cin >> x >> d >> k;

        for (int i = x; i <= N; i += x)
        {
            // �̵� �� ������ ����
            int temp_circle[51];
            for (int j = 0; j < M; ++j)
            {
                // ������ ����Ǿ� �ִٴ� ���� ����
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

            // �̵� ���� ������ ���� ���ǿ� �����.
            copy(begin(temp_circle), end(temp_circle), begin(circles[i]));
        }

        // ������ ���� �־�δ� vector
        vector<vector<type>> delete_nums;
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                // BFS�� ���� ���� �����ϸ鼭 ���� ���� Ž��
                if (visited[i][j] == false && circles[i][j] != 0)
                {
                    // ���� ���� �����鼭 ������ ���� ��ġ�� ���Ϳ� �ִ´�.
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

                            // next_y�� �����̹Ƿ� ó���� ���� �����ϴ�.
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

                    // ������ ���� �ִٸ� delete_nums�� �ִ´�.
                    if (delete_num.size() >= 2)
                    {
                        delete_nums.push_back(delete_num);
                    }
                }
            }
        }

        memset(visited, false, sizeof(visited));

        // ������ ���� �ִٸ� �ش� ���� 0���� �����Ѵ�.
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
            // ������ ���� ���� ��� ������ ���� ����� ���ϰ�
            // ��հ� ���Ͽ� ���� ó���Ѵ�.
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