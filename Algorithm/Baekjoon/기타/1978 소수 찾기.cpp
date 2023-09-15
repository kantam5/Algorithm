#include <iostream>

using namespace std;

int main()
{
    int num1;
    cin >> num1;

    int prime = 0;
    for (int i = 0; i < num1; i++)
    {
        int temp;
        cin >> temp;

        if (temp == 1)
        {
            continue;
        }

        bool bprime = true;
        for (int i = 2; i < temp; i++)
        {
            if (temp % i == 0)
            {
                bprime = false;
                break;
            }
        }
        if (!bprime)
        {
            continue;
        }

        prime++;
    }

    cout << prime << endl;

    return 0;
}