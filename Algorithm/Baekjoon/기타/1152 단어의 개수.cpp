#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    string _string = "";
    getline(cin, _string);

    int result = 0;

    for (int i = 0; i < _string.size(); i++)
    {
        if (_string[i] == ' ' && i != 0 && i != _string.size() - 1)
        {
            result++;
        }
    }

    // 공백만 있는 경우
    if (_string == " ")
    {
        cout << 0;
    }
    else
    {
        cout << result + 1;
    }

    return 0;
}