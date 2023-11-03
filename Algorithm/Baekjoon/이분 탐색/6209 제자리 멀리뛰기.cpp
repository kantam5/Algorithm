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

    int d, n, m;
    cin >> d >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    // ���� ������ �� ������ �߰�
    nums.push_back(0);
    nums.push_back(d);
    sort(nums.begin(), nums.end());

    int start = 1;
    int end = d;
    int answer = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int current_deleted = 0;
        int pre_rock = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            // �� ���̿� mid��ŭ�� �Ÿ��� �� �ȴٸ� ���� ����
            if (nums[i] - nums[pre_rock] < mid)
            {
                current_deleted++;
            }
            else
            {
                // �������� �ʾ��� ��쿣 ���� ���� ����
                pre_rock = i;
            }
        }

        // ������ ���� ���� m�� ��
        if (current_deleted > m)
        {
            end = mid - 1;
        }
        else
        {
            answer = mid;
            start = mid + 1;
        }
    }

    cout << answer;

    return 0;
}