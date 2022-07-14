#include <iostream>
#include <string>

using namespace std;

int main()
{
    string num1;
    string num2;
    string temp;

    cin >> num1 >> num2;

    for (int i = 2; i >= 0; i--)
    {
        if (num1[i] > num2[i])
        {
            temp = num1;
            break;
        }
        else if (num1[i] < num2[i])
        {
            temp = num2;
            break;
        }
    }

    cout << temp[2] << temp[1] << temp[0];

    return 0;
}