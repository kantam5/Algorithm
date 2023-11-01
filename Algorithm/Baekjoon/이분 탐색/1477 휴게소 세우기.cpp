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
vector<int> dists;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, M, L;
    cin >> N >> M >> L;

    nums.push_back(0);
    nums.push_back(L);
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());

    // �ްԼҸ� ���� �� �ִ� �ּ� �Ÿ��� �ߺ��� �� �ǹǷ� 1�̴�.
    // �ִ� �Ÿ��� ��ӵ��� ���������� ���� �� �����Ƿ� L - 1�̴�.
    int start = 1;
    int end = L - 1;
    int answer = 0;

    // mid�� �ֱ�� �ްԼҸ� ������ ��, M���� �񱳷� �̺� Ž��
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int current = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            // �ްԼҿ� �ްԼ� ������ �Ÿ� dist
            // dist�ȿ��� ���� �� �ִ� �ްԼ��� ���� dist / mid�̴�.
            // ��, nums[i]�� �ްԼҿ� �ߺ����� ���� �� ������ dist % mid == 0�̶�� 1�����Ѵ�.
            int dist = nums[i] - nums[i - 1];

            current += dist / mid;
            if (dist % mid == 0)
            {
                current--;
            }
        }

        if (current <= M)
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << answer;

    return 0;
}