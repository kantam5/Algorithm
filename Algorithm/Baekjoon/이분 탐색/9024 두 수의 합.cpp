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

vector<int> nums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, K;
        cin >> n >> K;

        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }

        sort(nums.begin(), nums.end());

        // �� ���� �հ� K�� ���� ���밪�� �ּڰ��� mini
        // mini�� ����� ������ �� answer
        int mini = INT_MAX;
        int answer = 1;

        // ������ ó������ ������ �˻�
        // K���� ���̿� ���� ������ �޸��ϸ� �̺� Ž��
        // i������ �ٸ� ������ ���� ���� �� ���� ���� ���� current�� ����.
        for (int i = 0; i < n; ++i)
        {
            int current = INT_MAX;

            // ���� �ٸ� ���� ���̹Ƿ� i + 1�������� �˻��Ѵ�.
            int start = i + 1;
            int end = n - 1;
            while (start <= end)
            {
                int mid = (start + end) / 2;

                // i�� mid������ �հ� K���� ���� �� ���� ���� ���� current
                current = min(current, abs(K - (nums[i] + nums[mid])));

                // i�� mid������ �հ� K���� ���̿� ���� ���� ����
                if (nums[i] + nums[mid] >= K)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            // i�� mid������ �հ� K���� ���̰� mini�� ���ٸ� answer ����
            if (current == mini)
            {
                answer++;
            }
            // �� �۴ٸ� mini�� ����
            else if (current < mini)
            {
                mini = current;
                answer = 1;
            }
        }

        cout << answer << '\n';

        nums.clear();
    }

    return 0;
}