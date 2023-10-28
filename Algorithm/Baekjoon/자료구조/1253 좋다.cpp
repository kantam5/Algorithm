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

    // ������ ��� ��츦 unordered_map�� ����
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            // �հ� �Բ� �ǿ����ڵ��� �����Ѵ�.
            sums[inputs[i] + inputs[j]].push_back(make_pair(i, j));
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        // inputs[i]�� unordered_map�� �ִ��� Ȯ��
        int find_num = inputs[i];
        if (sums.find(find_num) != sums.end())
        {
            bool flag = false;
            for (auto operand : sums[find_num])
            {
                // �ǿ����ڷ� �ڱ� �ڽ��� ����ִ��� Ȯ��
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