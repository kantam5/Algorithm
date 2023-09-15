#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num1;
    int num2;

    cin >> num1 >> num2;

    int* card = new int[num1];
    for (int i = 0; i < num1; i++)
    {
        cin >> card[i];
    }

    vector<int> result;

    for (int i = 0; i < num1; i++)
    {
        int temp = 0;
        for (int j = i + 1; j < num1; j++)
        {
            for (int k = j + 1; k < num1; k++)
            {
                temp = card[i] + card[j] + card[k];
                if (num2 < temp)
                {
                    continue;
                }
                else if (num2 == temp)
                {
                    cout << num2 << endl;
                    return 0;
                }
                else
                {
                    result.push_back(temp);
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < result.size(); i++)
    {
        if (max < result[i])
        {
            max = result[i];
        }
    }

    cout << max << endl;

    return 0;
}