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

int nums[200'000];
int num_count[100'001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    // start�� end ��� 0�������� �����Ѵ�.
    int start = 0;
    int end = 0;

    int answer = 0;
    // end�� N �̸����� �˻��Ѵ�.
    while (end < N)
    {
        // num[end]�� ���� ������ �߰��Ϸ��� ���̴�.
        // ���� �߰��Ϸ��� ���� K�� �̸��� ��쿡�� �߰��� �� �ִ�.
        if (num_count[nums[end]] < K)
        {
            // end �ε����� ���� ������ �߰��Ѵ�.
            num_count[nums[end]]++;
            end++;
            answer = max(answer, end - start);
        }
        // �߰��� �� ���� ��쿡�� start�� ������ ��������
        // �߰��Ϸ��� ���� �߰��� �� ���� ������ �����Ѵ�.
        else
        {
            num_count[nums[start]]--;
            start++;
        }
    }

    cout << answer;

    return 0;
}
