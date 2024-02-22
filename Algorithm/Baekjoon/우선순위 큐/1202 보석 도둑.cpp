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

vector<pair<int, int>> jewel;
vector<int> bag;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        int M, V;
        cin >> M >> V;
        jewel.push_back(make_pair(M, V));
    }
    for (int i = 0; i < K; ++i)
    {
        int C;
        cin >> C;
        bag.push_back(C);
    }

    // ������ ���� ��� ������������ ����
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    long long answer = 0;
    int index = 0;
    for (int i = 0; i < K; ++i)
    {
        // i�� ���濡 �� �� �ִ� ������ ��� pq�� �ִ´�.
        // index�� ���԰� ���� �������� �˻��ϸ�, index�� ������ �� �� ���� ������ pq�� �ִ´�.
        while (index < N && bag[i] >= jewel[index].first)
        {
            pq.push(jewel[index].second);
            index++;
        }

        // pq�� top���� i�� ���濡 �� �� �����鼭 ������ �ִ��� �����̴�.
        if (false == pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;

    return 0;
}



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

priority_queue<pair<int, int>> jewel;
multiset<int> bag;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        int M, V;
        cin >> M >> V;
        // ���� ��� ������ top�� ��ġ�ϵ���
        jewel.push(make_pair(V, M));
    }
    for (int i = 0; i < K; ++i)
    {
        int C;
        cin >> C;
        bag.insert(C);
    }

    long long answer = 0;
    for (int i = 0; i < N; ++i)
    {
        int V = jewel.top().first;
        int M = jewel.top().second;
        jewel.pop();

        // ������ ���� �� �ִ� �ּ� ũ���� ������ ã�´�.
        auto it = bag.lower_bound(M);
        if (it != bag.end())
        {
            // ���� �� �ִ� ������ �ִٸ� �߰��ϰ� ������ �����Ѵ�.
            answer += V;
            bag.erase(it);
        }
    }

    cout << answer;

    return 0;
}
