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

priority_queue<long long, vector<long long>, greater<long long>> pq;
vector<int> primes;
map<long long, bool> visited;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;
    cin >> K >> N;

    for (int i = 0; i < K; ++i)
    {
        int prime;
        cin >> prime;

        primes.push_back(prime);
    }
    pq.push(1);
    visited[1] = true;

    long long maxi = 0;

    while (N--)
    {
        long long current_mini = pq.top();
        pq.pop();

        for (int prime : primes)
        {
            long long current_value = current_mini * prime;

            if (visited.find(current_value) != visited.end())
            {
                continue;
            }

            if (pq.size() > N && current_value >= maxi)
            {
                continue;
            }

            pq.push(current_value);
            visited[current_value] = true;

            maxi = max(maxi, current_value);
        }
    }

    cout << pq.top();

    return 0;
}
