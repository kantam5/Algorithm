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

vector<pair<int, int>> v;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int L, P;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;

        v.push_back(make_pair(a, b));
    }

    cin >> L >> P;

    sort(v.begin(), v.end());

    int answer = 0;
    int current_index = 0;
    while (L > P)
    {
        // ���� ����� ������ �� �ִ� �����ҵ��� P�� �켱���� ť�� ������ �д�.
        while (current_index < N && P >= v[current_index].first)
        {
            pq.push(v[current_index].second);
            current_index++;
        }

        // ���� ����� ������ �� �ִ� ������ �߿��� ���� ���ᰡ ���� �����Ҹ� �湮�Ѵ�.
        if (!pq.empty())
        {
            P += pq.top();
            pq.pop();

            answer++;
        }
        else
        {
            // ���� ���� ����� ������ �� �ִ� �����Ұ� ���ٸ� -1 ���
            answer = -1;
            break;
        }
    }

    cout << answer;

    return 0;
}
