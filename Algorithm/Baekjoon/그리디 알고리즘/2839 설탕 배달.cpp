#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


int main()
{
    int sugar;
    cin >> sugar;

    int a = sugar / 5;
    int b;
    while (true)
    {
        if (a < 0)
        {
            cout << "-1" << endl;
            return 0;
        }
        if ((sugar - (5 * a)) % 3 == 0)
        {
            b = (sugar - (5 * a)) / 3;
            break;
        }
        a--;
    }

    cout << a + b << endl;

    return 0;
}