#include <iostream>

using namespace std;

int main()
{
    int repeat = 0;
    cin >> repeat;

    float* arr = new float[repeat];
    float max = 0.0f;
    float total = 0.0f;

    for (int i = 0; i < repeat; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int i = 0; i < repeat; i++)
    {
        arr[i] = (arr[i] / max) * 100;
        total += arr[i];
    }

    cout << (total / (float)repeat);

    delete[] arr;

    return 0;
}