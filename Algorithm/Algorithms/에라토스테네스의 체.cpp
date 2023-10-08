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

const int MAX = 1000001;

vector<int> v;
vector<int> answer;
bool prime[MAX];

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int maxi = 0;
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);

        maxi = max(maxi, temp);
    }

    answer.resize(N, 0);

    eratosthenes(maxi);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i == j)
            {
                continue;
            }

            if (prime[v[j]])
            {
                continue;
            }

            if (v[i] < v[j] && v[j] % v[i] == 0)
            {
                answer[i]++;
                answer[j]--;
            }
        }

    }

    for (int i = 0; i < N; ++i)
    {
        cout << answer[i] << " ";
    }

    return 0;
}