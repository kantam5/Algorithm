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

vector<int> inputs;
unordered_map<int, vector<pair<int, int>>> sums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        inputs.push_back(temp);
    }

    // 가능한 모든 경우를 unordered_map에 저장
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            // 합과 함께 피연산자들을 저장한다.
            sums[inputs[i] + inputs[j]].push_back(make_pair(i, j));
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        // inputs[i]가 unordered_map에 있는지 확인
        int find_num = inputs[i];
        if (sums.find(find_num) != sums.end())
        {
            bool flag = false;
            for (auto operand : sums[find_num])
            {
                // 피연산자로 자기 자신이 들어있는지 확인
                if (operand.first != i && operand.second != i)
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}