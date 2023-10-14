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

bool cache[2001][2001];
int num[2001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, M;

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> num[i];
    }

    cin >> M;

    // S와 E가 같다면 true
    for (int i = 1; i <= N; ++i)
    {
        cache[i][i] = true;
    }

    // E == S + 1일 경우 두 수만 비교해서 같다면 true
    for (int i = 1; i < N; ++i)
    {
        if (num[i] == num[i + 1])
        {
            cache[i][i + 1] = true;
        }
    }

    while (M--)
    {
        int S;
        int E;
        cin >> S >> E;

        // 양 끝에서 부터 검사를 시작
        // S에서의 값과 E에서의 값이 같으면서 그 사이의 수열이 팰린드롬이면 S와 E까지의 수열도 팰린드롬이다.
        // 점점 가운데로 향하면서 검사
        int temp_start = S;
        int temp_end = E;
        while (temp_start <= temp_end)
        {
            if (num[temp_start] == num[temp_end] && cache[temp_start][temp_end] == 1)
            {
                cache[S][E] = true;
                break;
            }
            else if (num[temp_start] != num[temp_end])
            {
                cache[S][E] = false;
                break;
            }

            temp_start++;
            temp_end--;
        }

        cout << cache[S][E] << '\n';
    }

    return 0;
}