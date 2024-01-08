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

typedef struct
{
    int r;
    int c;
    int s;
}rotation;

int N, M, K;
int nums[51][51];
int nums_temp[51][51];
vector<rotation> rotations;
int answer = INT_MAX;

void calcAnswer()
{
    for (int i = 1; i <= N; ++i)
    {
        int current = 0;

        for (int j = 1; j <= M; ++j)
        {
            current += nums_temp[i][j];
        }

        answer = min(answer, current);
    }
}

// (x1, y1), (x2, y2)로 이루어진 정사각형의 둘레를 회전
void rotate(int x1, int y1, int x2, int y2)
{
    int temp = nums_temp[x1][y1];

    // 좌
    for (int x = x1; x < x2; ++x)
    {
        nums_temp[x][y1] = nums_temp[x + 1][y1];
    }
    // 하
    for (int y = y1; y < y2; ++y)
    {
        nums_temp[x2][y] = nums_temp[x2][y + 1];
    }
    // 우
    for (int x = x2; x > x1; --x)
    {
        nums_temp[x][y2] = nums_temp[x - 1][y2];
    }
    // 상
    for (int y = y2; y > y1; --y)
    {
        nums_temp[x1][y] = nums_temp[x1][y - 1];
    }

    nums_temp[x1][y1 + 1] = temp;
}

void solution(vector<int> v)
{
    copy(&nums[0][0], &nums[0][0] + 51 * 51, &nums_temp[0][0]);

    for (int i = 0; i < v.size(); ++i)
    {
        rotation current = rotations[v[i]];

        int x1, y1, x2, y2;
        x1 = current.r - current.s;
        y1 = current.c - current.s;
        x2 = current.r + current.s;
        y2 = current.c + current.s;

        int diff = (x2 - x1) / 2;

        // 정사각형의 둘레에서부터 안쪽으로 범위를 축소시킨다.
        for (int j = 0; j < diff; ++j)
        {
            rotate(x1 + j, y1 + j, x2 - j, y2 - j);
        }
    }

    // 회전을 끝냈다면 현재 배열의 최솟값을 구한다.
    calcAnswer();
}

// dfs를 이용한 순열
void dfs(bool select[], int map[], int cnt, int n, int k, vector<int> v)
{
    if (cnt == k)
    {
        solution(v);

        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (select[i] == 1)
        {
            continue;
        }

        select[i] = true;
        v.push_back(map[i]);

        dfs(select, map, cnt + 1, n, k, v);

        v.pop_back();
        select[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> nums[i][j];
        }
    }

    for (int i = 0; i < K; ++i)
    {
        int r, c, s;
        cin >> r >> c >> s;

        rotations.push_back({ r, c, s });
    }

    bool select[6];
    memset(select, false, sizeof(select));
    int map[6] = { 0, 1, 2, 3, 4, 5 };
    vector<int> v;

    dfs(select, map, 0, K, K, v);

    cout << answer;

    return 0;
}
