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

using namespace std;

vector<int> shoots;
vector<pair<int, int>> animals;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int M, N, L;
    cin >> M >> N >> L;

    for (int i = 0; i < M; ++i)
    {
        int temp;
        cin >> temp;
        shoots.push_back(temp);
    }

    for (int i = 0; i < N; ++i)
    {
        int x;
        int y;
        cin >> x >> y;
        animals.push_back(make_pair(x, y));
    }

    // 사대를 정렬
    sort(shoots.begin(), shoots.end());

    // 각 동물마다 어느 위치의 사대에서 사냥이 가능한지 이분 탐색
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        int start = 0;
        int end = M - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            // mid 사대에서 사냥 가능인지 검사
            int dist = abs(animals[i].first - shoots[mid]) + animals[i].second;
            if (dist <= L)
            {
                answer++;
                break;
            }

            // 동물이 mid 사대의 왼쪽에 있다면 end를 감소
            // 오른쪽에 있다면 start를 증가
            if (animals[i].first < shoots[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }

    cout << answer;

    return 0;
}