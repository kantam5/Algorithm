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

vector<unsigned long long> nums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    // �˻�޴� �� �ð��� �̺� Ž���Ѵ�. 
    // �ּڰ��� 1, �ִ��� ���� �ɸ��� �ð��� ���� �ɻ�뿡�� ��� �޾��� ���� �����ߴ�.
    unsigned long long start = 1;
    unsigned long long end = *max_element(nums.begin(), nums.end()) * M;
    unsigned long long answer = end;
    while (start <= end)
    {
        unsigned long long mid = (start + end) / 2;

        unsigned long long current = 0;

        // mid �ð� ���� �� �ɻ�뿡�� �ɻ簡���� ����� ����
        // mid / nums[i]�̴�.
        for (int i = 0; i < N; ++i)
        {
            current += mid / nums[i];
        }

        // mid �ð����� �˻��� �� �ִ� ����� ���� M�� ���Ͽ� ���� ����
        if (current >= M)
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