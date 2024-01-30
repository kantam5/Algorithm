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

    long long N;
    cin >> N;

    // 최대한 작은 자연수부터 더하면서 마지막에 N을 만들 수 있도록 알 맞는 수를 더한다.
    // 1 + 2 + 3 + ... + (N을 만드는 수)
    long long sum = 0;
    long long current = 1;
    int answer = 0;
    while (sum <= N)
    {
        sum += current;
        current++;

        answer++;
    }

    cout << answer - 1;

    return 0;
}
