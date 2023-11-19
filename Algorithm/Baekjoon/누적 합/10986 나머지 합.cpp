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

// ������� ���� �� �߿��� mod������ ����� index�� ���� ���� ��´�.
// M�� 1000�����̹Ƿ� �ִ� �������� 999�̴�.
int mod[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // ���ݱ����� ���� sum
    // (sum - x) % M == 0�� ��쿡 ���� �����ϹǷ�,
    // ((sum % M) - (x % M) + M) % M == 0�� �����ؾ� �Ѵ�.
    // ��, sum % M == x % M�� x�� ���� answer�� �߰��ȴ�. 
    // sum % == 0�� ��쿡�� sum��ü�� answer�� �߰��Ǿ� �Ѵ�.
    long long answer = 0;
    long long sum = 0;
    for (int i = 0; i < N; ++i)
    {
        long long temp;
        cin >> temp;

        sum += temp;

        answer += mod[sum % M];
        if (sum % M == 0)
        {
            answer++;
        }

        mod[sum % M]++;
    }

    cout << answer;

    return 0;
}