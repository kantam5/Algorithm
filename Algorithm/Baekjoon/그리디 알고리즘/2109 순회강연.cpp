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

bool days[10001];
priority_queue<pair<int, int>> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int p, d;
        cin >> p >> d;

        pq.push(make_pair(p, d));
    }

    // �����ᰡ ũ�鼭, ���� �Ⱓ�� ���� ���� ������ Ž���Ѵ�. 
    int answer = 0;
    while (!pq.empty())
    {
        pair<int, int> current = pq.top();
        pq.pop();

        // ���� ������ �ִ��� �������� �̷�� �Ⱓ�� ª���鼭 �����ᰡ ū ������ ������ �� �ִ�. 
        for (int i = current.second; i > 0; --i)
        {
            if (days[i] == false)
            {
                days[i] = true;
                answer += current.first;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}
