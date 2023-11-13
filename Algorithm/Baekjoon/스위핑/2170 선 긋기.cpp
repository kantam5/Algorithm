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

vector<pair<int, int>> lines;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int start, end;
        cin >> start >> end;

        lines.push_back(make_pair(start, end));
    }

    // 선들을 정렬한다.
    sort(lines.begin(), lines.end());

    int answer = 0;
    int start = lines[0].first;
    int end = lines[0].second;
    for (int i = 1; i < lines.size(); ++i)
    {
        // 검사하는 선의 시작이 현재 긋는 선의 끝보다 작거나 같은 값이라면 한번에 그을 수 있다.
        if (lines[i].first <= end)
        {
            // 검사하는 선의 끝이 현재 긋는 선의 끝보다 크다면 검사하는 선의 끝까지 긋는다.
            if (end < lines[i].second)
            {
                end = lines[i].second;
            }
        }
        // 검사하는 선의 시작이 현재 긋는 선의 끝보다 크다면 새로 선을 그어야 한다.
        else
        {
            // 현재 긋고 있는 선의 길이를 answer에 추가하고
            // 새로운 선을 긋는다.
            answer += (end - start);
            start = lines[i].first;
            end = lines[i].second;
        }
    }
    // 마지막 선은 위의 반복문에서 들어가지 않으므로 따로 추가한다.
    answer += (end - start);

    cout << answer;

    return 0;
}