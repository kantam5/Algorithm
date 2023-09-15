#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int temp = 666;
    int count = 1;
    while (count < n)
    {
        temp++;

        string temp_string = to_string(temp);
        if (temp_string.find("666") != string::npos)
        {
            count++;
        }
    }

    cout << temp << endl;

    return 0;
}