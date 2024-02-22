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

// �������� �켱���� ť
priority_queue<int, vector<int>, greater<int>> pq;

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

        pq.push(temp);
    }

    // ī�� ���� ���� ���� 2���� ������ ��ģ��.
    // ������ ������ �ٽ� �켱���� ť�� �ִ´�.
    // ��� ī�� ������ ������ ������ �ݺ�
    int answer = 0;
    while (pq.size() > 1)
    {
        int deck1 = pq.top();
        pq.pop();
        int deck2 = pq.top();
        pq.pop();

        answer += (deck1 + deck2);

        pq.push((deck1 + deck2));
    }

    cout << answer;

    return 0;
}
