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

    // ��緹�� ũ���� �ּڰ��� lesson �� ���� ª�� �ð��̴�.
    int start = maxi;
    // ��緹�� ũ���� �ִ��� lesson �ð��� �� ���̴�.
    int end = total_time;
    int answer = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // mid��ŭ ��緹�� �ð��� �������� ��,
        // ��������� CD�� ��
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

        // ������� CD�� ���� M���� ũ�ٸ� ��緹�� �ð��� �ø���.
        if (CD > M)
        {
            start = mid + 1;
        }
        // ���϶�� answer�� �����ϰ� ��緹�� �ð��� ���δ�.
        else
        {
            answer = min(answer, mid);
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}