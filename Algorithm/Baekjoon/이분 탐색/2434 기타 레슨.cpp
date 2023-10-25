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

vector<int> lessons;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int total_time = 0;
    int maxi = 0;
    for (int i = 0; i < N; ++i)
    {
        int lesson;
        cin >> lesson;
        lessons.push_back(lesson);

        maxi = max(maxi, lesson);
        total_time += lesson;
    }

    // 블루레이 크기의 최솟값은 lesson 중 가장 짧은 시간이다.
    int start = maxi;
    // 블루레이 크기의 최댓값은 lesson 시간의 총 합이다.
    int end = total_time;
    int answer = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // mid만큼 블루레이 시간을 제한했을 때,
        // 만들어지는 CD의 수
        int CD = 1;
        int lesson_time = lessons[0];
        for (int i = 1; i < N; ++i)
        {
            if (lesson_time + lessons[i] > mid)
            {
                lesson_time = 0;
                CD++;
            }

            lesson_time += lessons[i];
        }

        // 만들어진 CD의 수가 M보다 크다면 블루레이 시간을 늘린다.
        if (CD > M)
        {
            start = mid + 1;
        }
        // 이하라면 answer를 갱신하고 블루레이 시간을 줄인다.
        else
        {
            answer = min(answer, mid);
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}