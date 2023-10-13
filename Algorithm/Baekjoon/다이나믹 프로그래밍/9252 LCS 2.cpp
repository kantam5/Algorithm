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

int cache[1001][1001];
// 경로를 저장하는 배열
pair<pair<int, int>, char> path[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    string a;
    string b;

    cin >> a >> b;

    a = '0' + a;
    b = '0' + b;

    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                cache[i][j] = 0;

                continue;
            }

            if (a[i] == b[j])
            {
                cache[i][j] = cache[i - 1][j - 1] + 1;
                // cache가 어디서부터 갱신되었는지 넣고, 문자도 넣는다.
                path[i][j] = make_pair(make_pair(i - 1, j - 1), a[i]);
            }
            else
            {
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
                // cache가 어디서부터 갱신되었는지 넣는다.
                path[i][j] = cache[i - 1][j] > cache[i][j - 1] ? make_pair(make_pair(i - 1, j), ' ')
                    : make_pair(make_pair(i, j - 1), ' ');

            }
        }
    }

    // LCS의 길이
    int answer = cache[a.length() - 1][b.length() - 1];

    // path의 마지막 부분에서부터 시작한다.
    string answer_string;
    int x = a.length() - 1;
    int y = b.length() - 1;
    while (answer_string.size() < answer)
    {
        // 문자도 추가되었었다면 answer_stirng에 push_back
        if (path[x][y].second != ' ')
        {
            answer_string.push_back(path[x][y].second);
        }
        // 해당 cache의 부모 cache로 이동
        int temp_x = path[x][y].first.first;
        int temp_y = path[x][y].first.second;
        x = temp_x;
        y = temp_y;
    }
    // 경로는 거꾸로 돌아서 추적했기에 string을 거꾸로 돌린다.
    reverse(answer_string.begin(), answer_string.end());

    cout << answer << endl;
    cout << answer_string;

    return 0;
}


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

int cache[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    string a;
    string b;

    cin >> a >> b;

    a = '0' + a;
    b = '0' + b;

    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                cache[i][j] = 0;

                continue;
            }

            if (a[i] == b[j])
            {
                cache[i][j] = cache[i - 1][j - 1] + 1;

            }
            else
            {
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
            }
        }
    }

    int x = a.length() - 1;
    int y = b.length() - 1;

    // LCS의 길이
    int answer = cache[x][y];
    string answer_string;

    // 마지막 에서부터 역추적
    while (cache[x][y])
    {
        // 위의 행에서부터 온 cache라면 x--
        if (cache[x][y] == cache[x - 1][y])
        {
            x--;
        }
        // 왼쪽의 열에서부터 온 cache라면 y--
        else if (cache[x][y] == cache[x][y - 1])
        {
            y--;
        }
        // 대각선에서부터 온 cache라면 answer_string에 추가하고 x--, y--
        else
        {
            answer_string.push_back(a[x]);
            x--;
            y--;
        }
    }
    // 역추적 했기에 거꾸로 돌린다.
    reverse(answer_string.begin(), answer_string.end());

    cout << answer << endl;
    cout << answer_string;

    return 0;
}