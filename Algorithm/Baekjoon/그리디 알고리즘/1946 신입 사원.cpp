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

vector<pair<int, int>> nums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        for (int i = 0; i < N; ++i)
        {
            int A, B;
            cin >> A >> B;
            nums.push_back(make_pair(A, B));
        }

        sort(nums.begin(), nums.end());

        // 0���� �����ɻ� ������ ���� ���� ������, ������ ���ߵȴ�. 
        // 1���� 0������ �����ɻ� ������ ������, ���� ������ ���� �� �ִ�. 
        // 1���� 0������ ���� ������ ���ٸ�, ���ߵȴ�. 
        // 2���� 1������ �����ɻ� ������ ���̳�, ���� ������ ���� �� �ִ�. 
        // ���� ������ ĿƮ������ 0���� ���� �������� 1���� ���� �������� �����Ѵ�. 
        // �ݺ�
        int maxi = nums[0].second;
        int current = 1;
        for (int i = 1; i < N; ++i)
        {
            if (maxi > nums[i].second)
            {
                maxi = nums[i].second;
                current++;
            }
        }

        cout << current << '\n';

        nums.clear();
    }

    return 0;
}
