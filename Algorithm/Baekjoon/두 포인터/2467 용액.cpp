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

int main()
{
    int N;
    vector<int> v;
    vector<int> answer;

    cin >> N;
    v.resize(N);
    answer.resize(2);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    int start = 0;
    int end = N - 1;
    answer[0] = v[start];
    answer[1] = v[end];

    // vector의 양쪽에서 다가오면서 start가 end를 넘어설 때 까지 검사
    while (start < end)
    {
        // 현재 start와 end의 합의 절댓값이 answer의 절댓값보다 작다면 갱신
        if (abs(answer[0] + answer[1]) > abs(v[start] + v[end]))
        {
            answer[0] = v[start];
            answer[1] = v[end];
        }

        // 합이 0보다 작다면 음수의 절댓값이 크므로 start를 1증가
        if (v[start] + v[end] < 0)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    cout << answer[0] << " " << answer[1];

    return 0;
}