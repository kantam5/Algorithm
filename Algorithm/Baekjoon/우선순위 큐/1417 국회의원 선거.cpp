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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int pivot;
    cin >> pivot;

    for (int i = 1; i < N; ++i)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    // pq의 top에는 다솜이를 제외한 가장 많은 득표수가 위치한다.
    int count = 0;
    while (!pq.empty() && pivot <= pq.top())
    {
        int temp = pq.top();
        pq.pop();
        pq.push(temp - 1);

        pivot++;

        count++;
    }

    cout << count;

    return 0;
}
