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
    string s;
    string bomb;

    cin >> s >> bomb;

    string answer;

    int bomb_len = bomb.length();

    for (int i = 0; i < s.length(); ++i)
    {
        answer.push_back(s[i]);

        // ������� ä������ answer�� ���̰� ��ź ���̺��� Ŭ ��츸 ��
        if (answer.length() >= bomb_len)
        {
            // answer�� �� �κ��� ��ź�� ���ٸ� ����
            bool flag = true;
            for (int j = 0; j < bomb.length(); ++j)
            {
                if (answer[answer.length() - bomb_len + j] != bomb[j])
                {
                    flag = false;
                }
            }

            // ��ź �κ� ����
            if (flag)
            {
                answer.erase(answer.end() - bomb_len, answer.end());
            }
        }
    }

    if (answer.empty())
    {
        cout << "FRULA";
    }
    else
    {
        cout << answer;
    }

    return 0;
}