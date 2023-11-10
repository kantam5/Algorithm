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
            // ���� ĭ�� ���̰� ���ٸ� continue
            if (prev == nums[x][y])
            {
                continue;
            }

            // ���� ĭ���� �������� 2�̻��� ���
            if (abs(nums[x][y] - prev) >= 2)
            {
                flag = true;
            }

            // ���� ĭ���� ���̰� 1ĭ ���ٸ�
            if (nums[x][y] - prev == 1)
            {
                // ���� ĭ�������� ���θ� ���� ĭ���� �˻��Ѵ�. 
                for (int k = y - 1; k >= y - L; --k)
                {
                    // ���θ� ���� ĭ�� ���̰� ���� ��ġ���� �ʴ� ���
                    // ĭ�� �̹� ���ΰ� ��ġ�� ���
                    // ���ΰ� ������ ������ ��� ���
                    if (nums[x][k] != prev || block[x][k] || y - L < 0)
                    {
                        flag = true;
                        break;
                    }
                    else
                    {
                        // ���ǿ� �´´ٸ� ���θ� ��ġ�Ѵ�.
                        block[x][k] = true;
                    }
                }
            }

            // ���� ĭ ���� ���̰� 1ĭ ���ٸ�
            if (prev - nums[x][y] == 1)
            {
                // ���� ĭ�������� ���θ� ���� ĭ���� �˻��Ѵ�.
                for (int k = y; k <= y + L - 1; ++k)
                {
                    if (k < N)
                    {
                        // ���θ� ���� ĭ�� ���̰� ���� ��ġ���� �ʴ� ���
                        // ĭ�� �̹� ���ΰ� ��ġ�� ���
                        // ���ΰ� ������ ������ ��� ���
                        if (nums[x][k] != nums[x][y] || block[x][k] || y + L - 1 >= N)
                        {
                            flag = true;
                            break;
                        }
                        else
                        {
                            // ���ǿ� �´´ٸ� ���θ� ��ġ�Ѵ�.
                            block[x][k] = true;
                        }
                    }
                }
            }

            if (flag)
            {
                break;
            }

            // ���� ĭ�� ����
            prev = nums[x][y];
        }

        // flag�� true�� ��� �信�� 1����
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