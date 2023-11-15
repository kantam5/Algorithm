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

// 투 포인터로 양 옆에서 접근하며 팰린드롬을 체크한다. 
int solution(string current, int start, int end, int in_diff_count)
{
    int diff_count = in_diff_count;
    while (start <= end)
    {
        if (current[start] == current[end])
        {
            start++;
            end--;
            continue;
        }

        // current[start]와 current[end]가 서로 맞지 않다면
        if (current[start] != current[end])
        {
            // diff_count를 1 증가시킨다. 
            diff_count++;
            // 이미 diff_count가 1인 상태에서 함수가 실행되었다면
            // 재귀를 하지 않고 즉시 diff_count를 반환한다.
            if (diff_count > 1)
            {
                break;
            }

            // start와 end 둘 중 하나를 삭제한 상태에서 다시 투 포인터를 실시하도록 재귀한다.
            diff_count = min(solution(current, start + 1, end, diff_count),
                solution(current, start, end - 1, diff_count));

            break;
        }
    }

    return diff_count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        string current;
        cin >> current;

        int start = 0;
        int end = current.length() - 1;

        int diff_count = solution(current, start, end, 0);

        cout << diff_count << '\n';
    }

    return 0;
}