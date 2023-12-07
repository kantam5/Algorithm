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

int nums[1000];
vector<int> sums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    // x + y + z = k ���� x + y�� ������ ���� ��� ���س��´�.
    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            sums.push_back(nums[i] + nums[j]);
        }
    }

    // ���� ū �� ���� Ȯ���ϸ� �� ������ �����Ƿ� ����
    sort(nums, nums + N);
    // �̺� Ž���� ���� �յ��� ����
    sort(sums.begin(), sums.end());

    // ū �� ���� Ž���Ѵ�.
    // x + y = k - z �� �����ϹǷ� sums���� (k - z)�� �̺�Ž���ϸ� �߰� �� �ٷ� ����
    for (int k = N - 1; k >= 0; --k)
    {
        for (int z = k; z >= 0; --z)
        {
            if (binary_search(sums.begin(), sums.end(), nums[k] - nums[z]))
            {
                cout << nums[k];
                return 0;
            }
        }
    }

    return 0;
}
