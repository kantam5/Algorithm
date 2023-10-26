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

vector<int> lower;
vector<int> high;
vector<int> destroyed;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, H;
    cin >> N >> H;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;

        if (i % 2 == 0)
        {
            lower.push_back(temp);
        }
        else
        {
            high.push_back(temp);
        }
    }

    sort(lower.begin(), lower.end());
    sort(high.begin(), high.end());

    for (int i = 1; i <= H; ++i)
    {
        int destroy = 0;

        // ������ ���̰� i �����̸� �μ�����.
        destroy += lower.end() - lower_bound(lower.begin(), lower.end(), i);
        // �������� ���̰� (H -i) �ʰ���� �μ�����.
        destroy += high.end() - upper_bound(high.begin(), high.end(), (H - i));

        // i���̿��� �μ��� ��
        destroyed.push_back(destroy);
    }

    // ���� ���� �μ��� ���� destroyed[0]�̰�
    // �ش� ������ ���̰� ��ֹ��� �ּ��� ������ ���̴�.
    sort(destroyed.begin(), destroyed.end());

    int answer = destroyed[0];
    int answer_count = upper_bound(destroyed.begin(), destroyed.end(), answer)
        - lower_bound(destroyed.begin(), destroyed.end(), answer);

    cout << answer << " " << answer_count;

    return 0;
}