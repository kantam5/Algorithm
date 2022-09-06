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

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int M;
    cin >> N >> M;

    bool button[10] = { false };
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        button[temp] = true;
    }

    int result = abs(100 - N);
    for (int i = 0; i <= 1000000; i++)
    {
        bool flag = true;

        string string_i = to_string(i);
        for (int j = 0; j < string_i.size(); j++)
        {
            // 필요한 버튼이 고장난 경우
            if (button[(int)string_i[j] - 48] == true)
            {
                flag = false;
            }
        }
        if (flag == false)
        {
            continue;
        }

        result = min(result, abs(i - N) + (int)string_i.size());
    }

    cout << result << '\n';

    return 0;
}