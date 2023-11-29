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

using namespace std;

int nums[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // ������ �Է¹ް� �����Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
    sort(nums, nums + N);

    int start = 0;
    int end = 0;
    int answer = INT_MAX;
    while (start <= end && end < N)
    {
        int current = nums[end] - nums[start];

        // start�� end�� ���̰� M�̻��̶�� ���� �����Ѵ�. 
        // ���̸� �� ���̱� ���� start�� ������Ų��.
        if (current >= M)
        {
            answer = min(answer, current);
            start++;
        }
        // �̸��̶�� ���̸� �� �ø��� ���� end�� ������Ų��.
        else
        {
            end++;
        }
    }

    cout << answer;

    return 0;
}
