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
    int index;      // ������ ������ ���̹Ƿ�, ���� ���� �ε��� ��ǥ�� �ʿ��ϴ�.
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

    // ������ ũ�� ������ �����Ѵ�.
    sort(balls.begin(), balls.end(), compare);

    answer.resize(N);

    // 0������ �����Ͽ� i������ ���� ���� ���Ѵ�. �� �տ��� �ʿ���� �κ��� ���� ������� ���� ���Ѵ�. 
    // ������� ���� �տ��� �� ���� ������ ����. 
    // 1. ���� ���� ���� ���� ��
    // 2. ���� ���� ���� ũ���� ���� ��
    // �̷��� ���ٸ� ���� ���� ���� �� �߿���, ���� ���� ����� ũ�Ⱑ ���� ���� �ߺ����� ������. 
    // �׷��Ƿ�, �ߺ����� ���� ���� �ѹ� �����־�� ���� �ùٸ���.
    for (int i = 0; i < N; ++i)
    {
        ball current = balls[i];

        sum += current.size;

        color_sum[current.color] += current.size;
        size_sum[current.size] += current.size;
        ball_count[make_pair(current.color, current.size)]++;

        // ���� ���� ���� ���� �� �ε����� �ִ´�.
        answer[current.index] = sum - color_sum[current.color] - size_sum[current.size]
            + current.size * ball_count[make_pair(current.color, current.size)];
    }

    for (int i = 0; i < N; ++i)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}