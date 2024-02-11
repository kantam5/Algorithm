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

vector<int> hole;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        hole.push_back(temp);
    }

    // 정렬 필수
    sort(hole.begin(), hole.end());

    // 현재 구멍 i에서 테이프를 붙였을 때, 막을 수 있는 구멍의 거리는 hole[i] + L - 1 까지이다.
    // 이 거리보다 먼 구멍은 막을 수 없으므로, 새로운 테이프를 사용해야 한다. 
    int answer = 0;
    int start = hole[0];
    for (int i = 0; i < N; ++i)
    {
        if (hole[i] > start + L - 1)
        {
            // start를 갱신한다.
            start = hole[i];
            answer++;
        }
    }

    // 마지막 start에서 사용하는 테이프
    cout << answer + 1;

    return 0;
}
