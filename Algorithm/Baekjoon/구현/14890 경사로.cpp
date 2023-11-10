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

int nums1[101][101];
int nums2[101][101];
bool block[101][101];

int N, L;
int answer;

void solution(int nums[][101])
{
    for (int x = 0; x < N; ++x)
    {
        bool flag = false;

        int prev = nums[x][0];
        for (int y = 1; y < N; ++y)
        {
            // 이전 칸과 높이가 같다면 continue
            if (prev == nums[x][y])
            {
                continue;
            }

            // 이전 칸과의 높이차가 2이상인 경우
            if (abs(nums[x][y] - prev) >= 2)
            {
                flag = true;
            }

            // 이전 칸보다 높이가 1칸 높다면
            if (nums[x][y] - prev == 1)
            {
                // 이전 칸에서부터 경사로를 놓을 칸까지 검사한다. 
                for (int k = y - 1; k >= y - L; --k)
                {
                    // 경사로를 놓을 칸의 높이가 서로 일치하지 않는 경우
                    // 칸에 이미 경사로가 설치된 경우
                    // 경사로가 지도의 범위를 벗어난 경우
                    if (nums[x][k] != prev || block[x][k] || y - L < 0)
                    {
                        flag = true;
                        break;
                    }
                    else
                    {
                        // 조건에 맞는다면 경사로를 설치한다.
                        block[x][k] = true;
                    }
                }
            }

            // 이전 칸 보다 높이가 1칸 낮다면
            if (prev - nums[x][y] == 1)
            {
                // 현재 칸에서부터 경사로를 높을 칸까지 검사한다.
                for (int k = y; k <= y + L - 1; ++k)
                {
                    if (k < N)
                    {
                        // 경사로를 놓을 칸의 높이가 서로 일치하지 않는 경우
                        // 칸에 이미 경사로가 설치된 경우
                        // 경사로가 지도의 범위를 벗어난 경우
                        if (nums[x][k] != nums[x][y] || block[x][k] || y + L - 1 >= N)
                        {
                            flag = true;
                            break;
                        }
                        else
                        {
                            // 조건에 맞는다면 경사로를 설치한다.
                            block[x][k] = true;
                        }
                    }
                }
            }

            if (flag)
            {
                break;
            }

            // 이전 칸을 갱신
            prev = nums[x][y];
        }

        // flag가 true인 경우 답에서 1차감
        if (flag)
        {
            answer--;
        }
    }

    memset(block, false, sizeof(block));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    cin >> N >> L;

    for (int x = 0; x < N; ++x)
    {
        for (int y = 0; y < N; ++y)
        {
            cin >> nums1[x][y];
            nums2[y][x] = nums1[x][y];
        }
    }

    answer = 2 * N;
    solution(nums1);
    solution(nums2);

    cout << answer;

    return 0;
}