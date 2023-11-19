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

// 현재까지 나온 수 중에서 mod연산의 결과가 index인 것의 수를 담는다.
// M이 1000이하이므로 최대 나머지는 999이다.
int mod[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // 지금까지의 합인 sum
    // (sum - x) % M == 0인 경우에 답을 만족하므로,
    // ((sum % M) - (x % M) + M) % M == 0을 만족해야 한다.
    // 즉, sum % M == x % M인 x의 수가 answer에 추가된다. 
    // sum % == 0인 경우에는 sum자체도 answer에 추가되야 한다.
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