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
#include <sstream>
#include <cstdlib>

using namespace std;

int L, C;
vector<char> chars;
vector<char> answer;

bool check()
{
    // ������ 1�� �̻��̸� ������ 2���̻�
    int vowel = 0;

    for (int i = 0; i < answer.size(); ++i)
    {
        if (answer[i] == 'a' || answer[i] == 'e' || answer[i] == 'i' || answer[i] == 'o' || answer[i] == 'u')
        {
            vowel++;
        }
    }

    return (vowel >= 1) && (L - vowel >= 2);
}

void dfs(int index)
{
    // ������ ������ ���� L�� �����Ѵٸ� ���ǿ� �´��� �˻�
    if (answer.size() == L)
    {
        if (check())
        {
            for (int i = 0; i < answer.size(); ++i)
            {
                cout << answer[i];
            }
            cout << '\n';
        }

        return;
    }

    // ��Ʈ��ŷ���� ���ڸ� ����
    for (int i = index; i < C; ++i)
    {
        answer.push_back(chars[i]);
        dfs(i + 1);
        answer.pop_back();
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;

    for (int i = 0; i < C; ++i)
    {
        char temp;
        cin >> temp;

        chars.push_back(temp);
    }

    // �̸� ����
    sort(chars.begin(), chars.end());

    dfs(0);

    return 0;
}
