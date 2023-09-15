#include <iostream>

using namespace std;

int main()
{
    int repeat = 0;
    cin >> repeat;

    for (int i = 0; i < repeat; i++)
    {
        int total_floor = 0;
        int total_room = 0;
        int guest = 0;
        cin >> total_floor >> total_room >> guest;

        int floor = guest % total_floor;
        int room = guest / total_floor;
        if (floor > 0)
        {
            room++;
        }
        else
        {
            floor = total_floor;
        }

        cout << floor * 100 + room << endl;
    }

    return 0;
}