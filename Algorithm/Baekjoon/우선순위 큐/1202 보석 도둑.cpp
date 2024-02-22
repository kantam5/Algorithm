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

    // 보석과 가방 모두 오름차순으로 정렬
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    long long answer = 0;
    int index = 0;
    for (int i = 0; i < K; ++i)
    {
        // i번 가방에 들어갈 수 있는 보석을 모두 pq에 넣는다.
        // index로 무게가 작은 보석부터 검사하며, index번 보석이 들어갈 수 없을 때까지 pq에 넣는다.
        while (index < N && bag[i] >= jewel[index].first)
        {
            pq.push(jewel[index].second);
            index++;
        }

        // pq의 top에는 i번 가방에 들어갈 수 있으면서 가격이 최대인 보석이다.
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
        // 가장 비싼 보석이 top에 위치하도록
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

        // 보석을 넣을 수 있는 최소 크기의 가방을 찾는다.
        auto it = bag.lower_bound(M);
        if (it != bag.end())
        {
            // 넣을 수 있는 가방이 있다면 추가하고 가방을 삭제한다.
            answer += V;
            bag.erase(it);
        }
    }

    cout << answer;

    return 0;
}
