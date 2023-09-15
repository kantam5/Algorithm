#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int repeat;
    cin >> repeat;

    string* parenthesis = new string[repeat];
    for (int i = 0; i < repeat; i++)
    {
        cin >> parenthesis[i];
    }

    for (int i = 0; i < repeat; i++)
    {
        bool exit_loop = false;
        int temp1 = 0;
        int temp2 = 0;
        for (int j = 0; j < parenthesis[i].size(); j++)
        {
            if (parenthesis[i][j] == '(')
            {
                temp1++;
            }
            if (parenthesis[i][j] == ')')
            {
                temp2++;
                if (temp1 < temp2)
                {
                    cout << "NO" << endl;

                    exit_loop = true;
                    break;
                }
            }
        }
        if (exit_loop == true)
        {
            continue;
        }

        if (temp1 != temp2)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }

    return 0;
}



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int repeat;
    cin >> repeat;

    string parenthesis;

    for (int i = 0; i < repeat; i++)
    {
        string result = "YES";
        cin >> parenthesis;

        stack<char> s;

        for (int j = 0; j < parenthesis.size(); j++)
        {
            if (parenthesis[j] == '(')
            {
                s.push('(');
            }
            else if (!s.empty() && parenthesis[j] == ')' && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                result = "NO";
                break;
            }
        }

        if (!s.empty())
        {
            result = "NO";
        }

        cout << result << endl;
    }

    return 0;
}