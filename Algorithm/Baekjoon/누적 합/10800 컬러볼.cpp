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

typedef struct
{
    int color;
    int size;
    int index;      // 공들을 정렬할 것이므로, 정렬 전의 인덱스 좌표가 필요하다.
}ball;

vector<ball> balls;
int sum;
map<int, int> color_sum;
map<int, int> size_sum;
map<pair<int, int>, int> ball_count;
vector<int> answer;

bool compare(const ball& a, const ball& b)
{
    return a.size < b.size;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int color, size;
        cin >> color >> size;

        balls.push_back({ color, size, i });
    }

    // 공들을 크기 순으로 정렬한다.
    sort(balls.begin(), balls.end(), compare);

    answer.resize(N);

    // 0번부터 접근하여 i번까지 공의 합을 구한다. 그 합에서 필요없는 부분을 빼는 방법으로 답을 구한다. 
    // 현재까지 공의 합에서 뺄 것은 다음과 같다. 
    // 1. 현재 색과 같은 공의 합
    // 2. 현재 공과 같은 크기의 공의 합
    // 이렇게 뺀다면 현재 까지 나온 공 중에서, 현재 공과 색상과 크기가 같은 공은 중복으로 빼진다. 
    // 그러므로, 중복으로 빠진 공은 한번 더해주어야 답이 올바르다.
    for (int i = 0; i < N; ++i)
    {
        ball current = balls[i];

        sum += current.size;

        color_sum[current.color] += current.size;
        size_sum[current.size] += current.size;
        ball_count[make_pair(current.color, current.size)]++;

        // 답을 현재 공의 정렬 전 인덱스에 넣는다.
        answer[current.index] = sum - color_sum[current.color] - size_sum[current.size]
            + current.size * ball_count[make_pair(current.color, current.size)];
    }

    for (int i = 0; i < N; ++i)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}