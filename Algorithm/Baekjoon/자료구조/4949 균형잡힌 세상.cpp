#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


int main()
{
    while (true)
    {
        string parenthesis;
        getline(cin, parenthesis);
        if (parenthesis == ".")
        {
            break;
        }

        stack<char> s;
        bool flag = true;
        for (int i = 0; i < parenthesis.size(); i++)
        {
            if (parenthesis[i] == '(' || parenthesis[i] == '[')
            {
                s.push(parenthesis[i]);
            }
            else if (parenthesis[i] == ')')
            {
                if (!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (parenthesis[i] == ']')
            {
                if (!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }

        if (s.empty() && flag == true)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}