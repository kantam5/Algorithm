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

int sum[100001];
int honey[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> honey[i];
        sum[i] = sum[i - 1] + honey[i];
    }

    int answer = 0;

    // 문제의 답은 밑의 종류 중 하나이다.
    // 벌집이 가운데 어딘가에 있고, 벌이 양측에서 접근하는 경우
    // 벌집이 1, N 둘 중 하나의 위치에 있고, 한 벌은 벌집의 반대편, 한 벌은 가운데 어딘가에 위치하는 경우
    // 벌집이 1, N 둘 중 하나의 위치에 있을 때, 한 벌은 가장 반대편에 있는게 제일 유리하다.

    // 벌 - 꿀통 - 벌
    for (int hive = 2; hive < N; ++hive)
    {
        int current = (sum[hive] - honey[1]) + (sum[N - 1] - sum[hive - 1]);
        answer = max(answer, current);
    }

    // 꿀통 - 벌 - 벌
    for (int bee = 2; bee < N; ++bee)
    {
        int current = (sum[bee - 1]) + (sum[N - 1] - honey[bee]);
        answer = max(answer, current);
    }

    // 벌 - 벌 - 꿀통
    for (int bee = 2; bee < N; ++bee)
    {
        int current = (sum[N] - sum[bee]) + (sum[N] - honey[1] - honey[bee]);
        answer = max(answer, current);
    }

    cout << answer;

    return 0;
}