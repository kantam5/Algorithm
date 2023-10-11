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

int num[100'002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, S;
    int sum = 0;
    int answer = INT_MAX;

    cin >> N >> S;

    for (int i = 1; i <= N; ++i)
    {
        cin >> num[i];
    }

    int start = 0;
    int end = 0;
    while (start <= end && end <= N)
    {
        if (sum >= S)
        {
            answer = min(answer, end - start + 1);
        }

        // ���� ���� �� �۴ٸ� end�� ������ �Űܼ� ���̸� �ø���.
        if (sum < S)
        {
            end++;
            sum += num[end];
        }
        // ���� ���� �� ũ�ٸ� start�� ������ �Űܼ� ���̸� ���δ�. 
        else
        {
            sum -= num[start];
            start++;
        }
    }

    // answer�� ������ ���ٸ� 0 ���
    if (answer == INT_MAX)
    {
        cout << "0";
        return 0;
    }
    cout << answer;

    return 0;
}