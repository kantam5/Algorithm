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

vector<int> levels;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, K;
    int answer = 0;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        int level;
        cin >> level;
        levels.push_back(level);
    }

    // �Է¹��� ������ �����Ѵ�.
    sort(levels.begin(), levels.end());

    // ���� ���� �� �ִ� �ּ� ������ levels[0]�� start�� �ȴ�.
    int start = levels[0];
    // ���� ���� �� �ִ� �ִ� ������ levels[N - 1] + k�� end�� �ȴ�.
    int end = levels[N - 1] + K;
    while (start <= end)
    {
        // mid���� ������ �÷��� ��츦 �˻��Ѵ�.
        int mid = (start + end) / 2;

        // ������ mid���� �ø� ������ �ʿ��� ������ ����
        long long need_levels = 0;
        for (int i = 0; i < N; ++i)
        {
            int need_level = mid - levels[i];
            if (need_level > 0)
            {
                need_levels += need_level;
            }
        }

        // �÷����� ������ K���� ���ٸ� �÷����� ������ ������Ų��.
        if (need_levels <= K)
        {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}