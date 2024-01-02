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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    bool flag = false;

    // ������ ���� �����ʺ��� �ٷ� ���� ���Ұ� �ڽź��� ������ �˻��Ѵ�.
    for (int i = N - 1; i > 0; --i)
    {
        // �۴ٸ� i - 1 ������ �������� ���ҵ� �� i - 1 ���Һ��� ū �� �� ���� ���� ���� ������ �ε����� ã�´�.
        if (nums[i - 1] < nums[i])
        {
            int index = i;

            for (int j = i; j < N; ++j)
            {
                if (nums[i - 1] < nums[j] && nums[index] > nums[j])
                {
                    index = j;
                }
            }

            // index�� i - 1�� ���Ҹ� swap
            swap(nums[i - 1], nums[index]);

            // i - 1�� �������� ������������ �����Ѵ�.
            sort(nums.begin() + i, nums.end());

            flag = true;

            break;
        }
    }

    if (flag)
    {
        for (int i = 0; i < N; ++i)
        {
            cout << nums[i] << " ";
        }
    }
    else
    {
        // ������ ������ ���� ��� -1�� ���
        cout << "-1";
    }

    return 0;
}
