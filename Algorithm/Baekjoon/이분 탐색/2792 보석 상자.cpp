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

    // ������ �ּ� 1�� ���� �� �� �ְ�
    // �ִ�δ� ���� ���� ���� ������ŭ ������ �� �ִ�. 
    int start = 1;
    int end = jewels[M - 1];
    int answer = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // ������ mid��ŭ ������ ��, current�� �л����� ������ �� �ִ�. 
        int current = 0;
        for (int i = 0; i < M; ++i)
        {
            // mid��ŭ �����شٸ� (���� ������ �� / mid)��ŭ�� �л����� ������ �� ������
            // �������� �ִٸ� �Ѹ��� �л����� �߰��� ������ �� �ִ�.
            current += jewels[i] / mid;

            if (jewels[i] % mid != 0)
            {
                current++;
            }
        }

        // mid��ŭ �������� ��, N���� ���ٸ� ������ ������ ���� ���δ�.
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