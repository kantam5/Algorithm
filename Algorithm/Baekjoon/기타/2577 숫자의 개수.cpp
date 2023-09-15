#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    int num_array[10];
    memset(num_array, 0, sizeof(num_array));

    cin >> num1 >> num2 >> num3;

    int temp = num1 * num2 * num3;

    string _string = to_string(temp);

    for (int i = 0; i < _string.size(); i++)
    {
        num_array[(int)_string[i] - 48]++;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << num_array[i] << endl;
    }

    return 0;
}