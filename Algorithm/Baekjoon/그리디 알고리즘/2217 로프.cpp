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

int nums[100000];

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

    // �������� ����
    sort(nums, nums + N, greater<int>());

    // i��° ������ ��ƿ �� �ִ� ���Դ� nums[i] * (��������� ���� ��)�̴�. 
    // 0��° �������� ���Ը� ���� ������� ���ϸ� �ִ� ���Ը� ã�´�.
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        answer = max(answer, (i + 1) * nums[i]);
    }

    cout << answer;

    return 0;
}
