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
// ��θ� �����ϴ� �迭
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
                // cache�� ��𼭺��� ���ŵǾ����� �ְ�, ���ڵ� �ִ´�.
                path[i][j] = make_pair(make_pair(i - 1, j - 1), a[i]);
            }
            else
            {
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
                // cache�� ��𼭺��� ���ŵǾ����� �ִ´�.
                path[i][j] = cache[i - 1][j] > cache[i][j - 1] ? make_pair(make_pair(i - 1, j), ' ')
                    : make_pair(make_pair(i, j - 1), ' ');

            }
        }
    }

    // LCS�� ����
    int answer = cache[a.length() - 1][b.length() - 1];

    // path�� ������ �κп������� �����Ѵ�.
    string answer_string;
    int x = a.length() - 1;
    int y = b.length() - 1;
    while (answer_string.size() < answer)
    {
        // ���ڵ� �߰��Ǿ����ٸ� answer_stirng�� push_back
        if (path[x][y].second != ' ')
        {
            answer_string.push_back(path[x][y].second);
        }
        // �ش� cache�� �θ� cache�� �̵�
        int temp_x = path[x][y].first.first;
        int temp_y = path[x][y].first.second;
        x = temp_x;
        y = temp_y;
    }
    // ��δ� �Ųٷ� ���Ƽ� �����߱⿡ string�� �Ųٷ� ������.
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

    // LCS�� ����
    int answer = cache[x][y];
    string answer_string;

    // ������ �������� ������
    while (cache[x][y])
    {
        // ���� �࿡������ �� cache��� x--
        if (cache[x][y] == cache[x - 1][y])
        {
            x--;
        }
        // ������ ���������� �� cache��� y--
        else if (cache[x][y] == cache[x][y - 1])
        {
            y--;
        }
        // �밢���������� �� cache��� answer_string�� �߰��ϰ� x--, y--
        else
        {
            answer_string.push_back(a[x]);
            x--;
            y--;
        }
    }
    // ������ �߱⿡ �Ųٷ� ������.
    reverse(answer_string.begin(), answer_string.end());

    cout << answer << endl;
    cout << answer_string;

    return 0;
}