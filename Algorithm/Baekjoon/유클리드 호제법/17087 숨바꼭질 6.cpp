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

vector<int> diffs;

int gcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }

    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    cin >> N >> S;

    // 현재 위치 S와의 차이를 저장
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;

        diffs.push_back(abs(temp - S));
    }

    // 모든 차이의 gcd를 출력
    int answer = diffs[0];
    for (int i = 1; i < diffs.size(); ++i)
    {
        answer = gcd(answer, diffs[i]);
    }

    cout << answer;

    return 0;
}
