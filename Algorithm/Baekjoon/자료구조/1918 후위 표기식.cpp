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

// ������ �켱����
unordered_map<char, int> priority = {
    {'(', 0},
    {'-', 1},
    {'+', 1},
    {'*', 2},
    {'/', 2}
};

int main()
{
    string s;
    stack<char> st;
    string answer;

    cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        if (65 <= int(s[i]) && int(s[i]) <= 90)
        {
            answer.push_back(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            // '('�� top�� ������ top�� answer�� ���� �߰��ϰ� pop
            while (st.top() != '(')
            {
                answer.push_back(st.top());
                st.pop();
            }
            // '('�� pop
            st.pop();
        }
        else
        {
            // ������ top�� s[i]���� ���� ������ top�� answer�� ���� �߰��ϰ� pop
            while (!st.empty() && priority.find(s[i])->second <= priority.find(st.top())->second)
            {
                answer.push_back(st.top());
                st.pop();
            }

            st.push(s[i]);
        }
    }

    // ���ÿ� ���� �����ڸ� answer�� ���� �߰�
    while (!st.empty())
    {
        answer.push_back(st.top());
        st.pop();
    }

    cout << answer;

    return 0;
}