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

const int MAX = 4'000'001;

bool prime[MAX];

// 에라토스테네스의 체
// N까지의 수 중 소수는 true로 표시
void eratosthenes(int N)
{
    memset(prime, false, sizeof(prime));

    for (int i = 2; i <= N; ++i)
    {
        prime[i] = true;
    }

    for (int i = 2; i * i <= N; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    eratosthenes(10000);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        int start = n / 2;

        for (int i = start; start >= 2; --start)
        {
            if (prime[start] == true && prime[n - start] == true)
            {
                cout << start << " " << n - start << '\n';
                break;
            }
        }
    }

    return 0;
}