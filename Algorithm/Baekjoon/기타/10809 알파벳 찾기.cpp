#include <iostream>
#include <string>

using namespace std;

int main()
{
    string _string;
    cin >> _string;

    int arr[26] = { -1 };

    memset(arr, -1, sizeof(arr));

    for (int i = 0; i < _string.size(); i++)
    {
        int index = (int)_string[i] - 97;
        if (arr[index] != -1)
        {
            continue;
        }
        arr[index] = i;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}