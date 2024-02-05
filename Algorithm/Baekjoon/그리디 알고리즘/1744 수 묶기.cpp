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

vector<int> negative;
vector<int> positive;
bool zero;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;

        if (temp < 0)
        {
            negative.push_back(temp);
        }
        else if (temp > 0)
        {
            positive.push_back(temp);
        }
        else
        {
            zero = true;
        }
    }

    long long answer = 0;

    // 절댓값이 가장 큰 순서대로 둘 씩 묶여야 한다. 
    // 음수의 개수가 홀수이면서, 0이 입력되었다면, 음수 중 절댓값이 가장 작은 음수는 0과 묶인다.
    sort(negative.begin(), negative.end());
    for (int i = 0; i < negative.size(); i += 2)
    {
        if (i + 1 < negative.size())
        {
            answer += negative[i] * negative[i + 1];
        }
        else if (i + 1 == negative.size())
        {
            if (zero == false)
            {
                answer += negative[i];
            }
        }
    }

    // 절댓값이 가장 큰 순서대로 둘 씩 묶여야 한다. 
    // 묶이는 수에 1이 있다면, 묶지 않는 경우가 더 큰 수를 만들 수 있으므로, 묶지 않고 더하기만 한다.
    sort(positive.begin(), positive.end(), greater<>());
    for (int i = 0; i < positive.size(); i += 2)
    {
        if (i + 1 < positive.size())
        {
            if (positive[i + 1] == 1)
            {
                answer += positive[i] + positive[i + 1];
            }
            else
            {
                answer += positive[i] * positive[i + 1];
            }

        }
        else if (i + 1 == positive.size())
        {
            answer += positive[i];
        }
    }

    cout << answer;

    return 0;
}
