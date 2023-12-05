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
bool num_count[100001];

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

    long long answer = 0;
    int start = 0;
    int end = 0;
    while (true)
    {
        // start�� �� �̻� �ø� �� ���� ������ �ݺ��Ѵ�.
        if (start >= N)
        {
            break;
        }

        // start���� �ߺ��Ǵ� ���� ���� ������ ������ �ø���.
        // Ȥ�� end�� N���� �����Ͽ� �� �̻� ������ �ø� �� ���� ������ �ø���.
        while (end < N && num_count[nums[end]] == false)
        {
            num_count[nums[end]] = true;
            end++;
        }

        // start���� end���� start�� �����Ͽ� ���� �� �ִ� ������ ������ end - start�̴�.
        answer += (end - start);

        // start�� ������ �ø���.
        num_count[nums[start]] = false;
        start++;
    }

    cout << answer;

    return 0;
}
