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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int six_mini = INT_MAX;
    int per_mini = INT_MAX;

    for (int i = 0; i < M; ++i)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        // 6줄 세트 최솟값, 1줄 최솟값
        six_mini = min(six_mini, temp1);
        per_mini = min(per_mini, temp2);
    }

    // 세트만 산 경우, 낱개로 산 경우, 세트와 낱개 혼합으로 산 경우 중 최솟값을 구한다.
    int answer = six_mini * (N / 6 + 1);
    answer = min(answer, per_mini * N);
    answer = min(answer, six_mini * (N / 6) + per_mini * (N % 6));

    cout << answer;

    return 0;
}
