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

        // ���̾��� �ε����� ���� �����Ѵ�.
        if (nums[i] == 1)
        {
            lion.push_back(i);
        }
    }

    // ���̾��� ���� K���� ���� ��� ������ ���� �� ����.
    if (lion.size() < K)
    {
        cout << "-1";
        return 0;
    }

    // ũ�Ⱑ K�� ������ �����̵� ������ ���
    // i���� ���� i + K - 1������ ������ ���� K���̴�.
    // lion[i + K - 1] - lion[i] + 1�� lion[i]�� ù ����̰� lion[i + K - 1]�� ������ ����� ������ �����̴�.
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
