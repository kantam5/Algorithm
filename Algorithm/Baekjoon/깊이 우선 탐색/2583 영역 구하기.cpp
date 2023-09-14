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

using namespace std;

int M;
int N;
int K;
int paper[101][101];
int visited[101][101];

int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };

vector<int> v_area;

// 빈 공간의 크기
int area = 0;

int dfs(int x, int y)
{
    area++;
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i)
    {
        int next_x = x + move_x[i];
        int next_y = y + move_y[i];
        if (next_x >= 0 && next_y >= 0 && next_x < M && next_y < N && !visited[next_x][next_y] && paper[next_x][next_y] == 0)
        {
            dfs(next_x, next_y);
        }
    }

    return area;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;
    // 모눈종이 직사각형 그리기
    while (K--)
    {
        int x1, x2;
        int y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        for (int i = x1; i < x2; ++i)
        {
            for (int j = y1; j < y2; ++j)
            {
                paper[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (paper[i][j] == 0 && !visited[i][j])
            {
                dfs(i, j);
                v_area.push_back(area);
                area = 0;
            }
        }
    }

    sort(v_area.begin(), v_area.end());

    cout << v_area.size() << endl;
    for (int area_in_v : v_area)
    {
        cout << area_in_v << " ";
    }

    return 0;
}