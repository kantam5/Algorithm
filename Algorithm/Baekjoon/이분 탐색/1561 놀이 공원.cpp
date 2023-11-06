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

vector<long long> nums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    long long maxi = 0;
    for (int i = 0; i < M; ++i)
    {
        long long temp;
        cin >> temp;
        nums.push_back(temp);

        maxi = max(maxi, temp);
    }

    if (N <= M)
    {
        cout << N;
        return 0;
    }

    long long start = 0;
    long long end = N * maxi;
    long long total_time = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;

        // 0���� ��, ���̱ⱸ�� ��� �� ������ current�� M���� ����
        long long current = M;
        for (int i = 0; i < M; ++i)
        {
            current += (mid / nums[i]);
        }

        if (current < N)
        {
            start = mid + 1;
        }
        else
        {
            total_time = mid;
            end = mid - 1;
        }
    }

    // (�ּҽð� - 1)�� ��, �� ���� Ż �� �ִ��� Ȯ��
    long long temp_time = total_time - 1;
    long long ridden = M;
    for (int i = 0; i < M; ++i)
    {
        ridden += (temp_time / nums[i]);
    }

    // ������ ����� �� �� ���̱ⱸ�� ������ Ȯ��
    for (int i = 0; i < M; ++i)
    {
        // �ּҽð��� Ž�� �ð��� ������ �������ٸ�, 
        // �ּҽð� ���� ���̱ⱸ�� ž���� �� �ִ�.
        if (total_time % nums[i] == 0)
        {
            ridden++;
        }
        if (ridden == N)
        {
            cout << i + 1;
            break;
        }
    }

    return 0;
}