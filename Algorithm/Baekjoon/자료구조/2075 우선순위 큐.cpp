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
        for (int j = 0; j < N; ++j)
        {
            int temp;
            cin >> temp;

            pq.push(temp);

            // �켱���� ť�� ����� N���� ũ�ٸ� pop
            // ������� ���� ���� ���� pop�ȴ�.
            if (pq.size() > N)
            {
                pq.pop();
            }
        }
    }

    cout << pq.top();

    return 0;
}
