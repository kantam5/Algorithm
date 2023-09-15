#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int apartment[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

int number_of_people(int k, int n)
{
    int result = 0;

    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            result += apartment[i];
        }

        return result;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            result += number_of_people(k - 1, i);
        }

        return result;
    }
}

int main()
{
    int repeat;
    cin >> repeat;

    for (int i = 0; i < repeat; i++)
    {
        int k;
        int n;
        cin >> k >> n;

        cout << number_of_people(k, n) << endl;
    }



    return 0;
}