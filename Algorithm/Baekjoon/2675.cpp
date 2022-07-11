#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int repeat = 0;
    cin >> repeat;

    for (int i = 0; i < repeat; i++)
    {
        int string_repeat = 0;
        string _string = "";

        cin >> string_repeat >> _string;

        for (int j = 0; j < _string.length(); j++)
        {
            for (int k = 0; k < string_repeat; k++)
            {
                cout << _string[j];
            }
        }
        cout << endl;
    }

    return 0;
}