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

priority_queue<int> smaller;                                // �ִ� ��
priority_queue<int, vector<int>, greater<int>> bigger;      // �ּ� ��

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int temp;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;

        // samller�� ũ��� bigger�� ũ�⺸�� 1 ũ�ų� ����.
        if (smaller.empty())
        {
            smaller.push(temp);
        }
        else if (smaller.size() == bigger.size())
        {
            smaller.push(temp);
        }
        else
        {
            bigger.push(temp);
        }

        // smaller�� �ִ��� bigger�� �ּڰ����� ũ�ٸ�, �� ���� ���� �ٲ�� �Ѵ�.
        if (!smaller.empty() && !bigger.empty() && smaller.top() > bigger.top())
        {
            // smaller�� �ִ� ���̹Ƿ� �ִ��� top�� ��ġ�Ѵ�.
            int small_top = smaller.top();
            smaller.pop();

            // bigger�� �ּ� ���̹Ƿ� �ּڰ��� top�� ��ġ�Ѵ�.
            int big_top = bigger.top();
            bigger.pop();

            smaller.push(big_top);
            bigger.push(small_top);
        }

        cout << smaller.top() << '\n';
    }

    return 0;
}
