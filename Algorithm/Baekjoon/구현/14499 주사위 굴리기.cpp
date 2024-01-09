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

int nums[20][20];
int order[1000];
int dice[6];    // 주사위 각 면에 적혀진 수

// 동 서 북 남
int move_x[4] = { 0, 0, -1, 1 };
int move_y[4] = { 1, -1, 0, 0 };
int D = 0;
int F = 4;
int R = 2;

// 주사위를 4방향으로 굴렸을 때, 아래, 오른쪽, 앞쪽의 주사위 눈의 변화
void moveDice(int dir)
{
    // 동 서 북 남
    if (dir == 0)
    {
        int temp = D;
        D = R;
        R = 5 - temp;
    }
    else if (dir == 1)
    {
        int temp = D;
        D = 5 - R;
        R = temp;
    }
    else if (dir == 2)
    {
        int temp = D;
        D = 5 - F;
        F = temp;
    }
    else if (dir == 3)
    {
        int temp = D;
        D = F;
        F = 5 - temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int x, y;
    int K;

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> nums[i][j];
        }
    }

    for (int i = 0; i < K; ++i)
    {
        cin >> order[i];
        order[i]--;
    }

    // 처음 주사위 밑의 수
    dice[D] = nums[x][y];

    for (int i = 0; i < K; ++i)
    {
        int current = order[i];

        int temp_x = x;
        int temp_y = y;

        x += move_x[current];
        y += move_y[current];

        // 지도의 범위를 초과한 경우
        if (x < 0 || x >= N || y < 0 || y >= M)
        {
            x = temp_x;
            y = temp_y;
            continue;
        }

        // 주사위 굴리기
        moveDice(current);

        if (nums[x][y] == 0)
        {
            nums[x][y] = dice[D];
        }
        else
        {
            dice[D] = nums[x][y];
            nums[x][y] = 0;
        }

        cout << dice[5 - D] << '\n';
    }

    return 0;
}
