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

priority_queue<int> pq;
vector<int> values[200'001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int deadline, value;
        cin >> deadline >> value;

        // deadline���� Ǯ �� �ִ� ����
        values[deadline].push_back(value);
    }

    // ù���� ��������� ���� ���� ������ Ǯ�� ���� Ǯ �� �ִ� ������ �����Ƿ� N�� ��¥�� Ǯ �������� �����Ѵ�. 
    // i�� ��¥�� Ǯ �� �ִ� ������ (i <= �������)�� �����̴�. 
    int answer = 0;
    for (int i = N; i > 0; --i)
    {
        // pq���� ��������� i�̻��� ������ ���� �ȴ�. 
        // �׷��Ƿ� pq�� top�� i�� ��¥�� Ǯ �� �ִ� ���� �߿��� value�� ���� ���� ������ �ȴ�.
        for (int value : values[i])
        {
            pq.push(value);
        }

        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;

    return 0;
}
