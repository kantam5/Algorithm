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

#define VER 0
#define HOR 1
#define DIA 2

using namespace std;

typedef struct
{
    int x;
    int y;
    int dir;
}type;

// �������� ���⿡ ���� �̵� ��ġ
vector<vector<int>> move_x = {
    {0, -1, 1},
    {-1, 1, 1},
    {0, 1, 1}
};
vector<vector<int>> move_y = {
    {1, -1, 1},
    {-1, 0, 1},
    {1, 0, 1}
};

// �������� ����� �̵� ��ġ�� ���� �˻� ��ġ
int check_x[3] = { 1, 1, 0 };
int check_y[3] = { 0 ,1, 1 };
//vector<vector<vector<int>>> check_x = {
//    {{0}, {}, {1, 1, 0}},
//    {{}, {1}, {1, 1, 0}},
//    {{0}, {1}, {1, 1, 0}}
//};
//vector<vector<vector<int>>> check_y = {
//    {{1}, {}, {0, 1, 1}},
//    {{}, {0}, {0, 1, 1}},
//    {{1}, {0}, {0, 1, 1}}
//};

int ground[17][17];
bool wall[17][17];
queue<type> bfs;

int main()
{
    int N;
    int answer = 0;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> ground[i][j];
            if (ground[i][j] == 1)
            {
                wall[i][j] = true;
            }
        }
    }

    bfs.push({ 0, 1, VER });

    while (!bfs.empty())
    {
        int current_x = bfs.front().x;
        int current_y = bfs.front().y;
        int current_dir = bfs.front().dir;
        bfs.pop();

        if (current_x == N - 1 && current_y == N - 1)
        {
            answer++;
        }

        // �������� �� �� �ִ� 3���� ��� (����, ����, �밢�� ����)
        for (int i = 0; i < 3; ++i)
        {
            // �̵� ����� ���� ���
            if (move_x[current_dir][i] == -1 || move_y[current_dir][i] == -1)
            {
                continue;
            }

            int next_x = current_x + move_x[current_dir][i];
            int next_y = current_y + move_y[current_dir][i];

            if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N || wall[next_x][next_y])
            {
                continue;
            }

            bool flag = true;

            // ������ �밢���� ��� �̵� �������� �˻�
            if (i == DIA)
            {
                for (int j = 0; j < 3; ++j)
                {
                    int next_check_x = current_x + check_x[j];
                    int next_check_y = current_y + check_y[j];

                    if (next_check_x < 0 || next_check_y < 0 || next_check_x >= N || next_check_y >= N
                        || wall[next_check_x][next_check_y])
                    {
                        flag = false;
                    }
                }
            }

            if (flag)
            {
                bfs.push({ next_x, next_y, i });
            }
        }
    }

    cout << answer;

    return 0;
}