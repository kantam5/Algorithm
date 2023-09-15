#include <iostream>

using namespace std;

int main()
{
    int side[3];

    while (true)
    {
        cin >> side[0] >> side[1] >> side[2];

        if (side[0] == 0 && side[1] == 0 && side[2] == 0)
        {
            return 0;
        }

        int max_side = side[0];
        int max_side_index = 0;
        int total_side_square = 0;

        for (int i = 1; i < 3; i++)
        {
            if (max_side < side[i])
            {
                max_side = side[i];
                max_side_index = i;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (i == max_side_index)
            {
                continue;
            }
            total_side_square += side[i] * side[i];
        }

        if (total_side_square == max_side * max_side)
        {
            cout << "right" << endl;
        }
        else
        {
            cout << "wrong" << endl;
        }
    }

    return 0;
}