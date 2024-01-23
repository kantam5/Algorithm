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

    int N, M;
    cin >> N >> M;

    // 소시지를 일자로 이어붙인 다음, 평론가에게 동일한 양을 주려면 N / M 등분해야 한다.
    // 그러므로, 결과적으로 소시지는 (M - 1)번 잘려야한다.
    // 소시지는 일자로 이어붙인 상태이므로, 이미 잘려있는 부분이 있다.
    // 이 잘려있는 부분이 (M - 1)번 자른 위치와 동일한 경우는 해당 부분은 횟수에서 제외해야 한다. 
    // 이 동일한 부분은 (N과 M의 최대공약수 - 1)개 있다.
    // 그러므로, 정답은 아래와 같다.
    cout << (M - 1) - (gcd(N, M) - 1);

    return 0;
}
