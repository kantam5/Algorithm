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

vector<int> jewels;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int temp;
        cin >> temp;
        jewels.push_back(temp);
    }
    sort(jewels.begin(), jewels.end());

    // 보석은 최소 1개 나눠 줄 수 있고
    // 최대로는 수가 가장 많은 보석만큼 나눠줄 수 있다. 
    int start = 1;
    int end = jewels[M - 1];
    int answer = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // 보석을 mid만큼 나눠줄 때, current의 학생에게 나눠줄 수 있다. 
        int current = 0;
        for (int i = 0; i < M; ++i)
        {
            // mid만큼 나눠준다면 (현재 보석의 수 / mid)만큼의 학생에게 나눠줄 수 있으며
            // 나머지가 있다면 한명의 학생에게 추가로 나눠줄 수 있다.
            current += jewels[i] / mid;

            if (jewels[i] % mid != 0)
            {
                current++;
            }
        }

        // mid만큼 나눠줬을 때, N보다 적다면 나눠줄 보석의 수를 줄인다.
        if (current <= N)
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << answer;

    return 0;
}