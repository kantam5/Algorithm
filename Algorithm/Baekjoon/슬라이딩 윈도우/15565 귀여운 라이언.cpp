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

using namespace std;

int nums[1000001];
vector<int> lion;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];

        // 라이언의 인덱스를 따로 저장한다.
        if (nums[i] == 1)
        {
            lion.push_back(i);
        }
    }

    // 라이언의 수가 K보다 작은 경우 집합을 만들 수 없다.
    if (lion.size() < K)
    {
        cout << "-1";
        return 0;
    }

    // 크기가 K로 고정된 슬라이딩 윈도우 방식
    // i에서 부터 i + K - 1까지의 원소의 수는 K개이다.
    // lion[i + K - 1] - lion[i] + 1이 lion[i]가 첫 요소이고 lion[i + K - 1]이 마지막 요소인 집합의 길이이다.
    int answer = INT_MAX;
    for (int start = 0; start < lion.size() - K + 1; ++start)
    {
        int end = start + K - 1;

        answer = min(answer, lion[end] - lion[start] + 1);
    }

    cout << answer;

    return 0;
}


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

using namespace std;

int nums[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    int start = 0;
    int end = 0;
    int current = 0;
    int answer = INT_MAX;
    while (end <= N)
    {
        if (current < K)
        {
            if (nums[end] == 1)
            {
                current++;
            }
            end++;
        }
        else
        {
            answer = min(answer, end - start);
            if (nums[start] == 1)
            {
                current--;
            }
            start++;
        }
    }

    if (answer == INT_MAX)
    {
        cout << "-1";
        return 0;
    }

    cout << answer;

    return 0;
}
