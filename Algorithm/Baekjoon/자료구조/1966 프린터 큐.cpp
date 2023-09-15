#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool higher(queue<pair<int, int>> q)
{
    int temp = q.front().first;
    int maxi = 0;

    while (!q.empty())
    {
        maxi = max(maxi, q.front().first);
        q.pop();
    }

    return temp < maxi;
}

int main()
{
    int repeat;
    cin >> repeat;

    for (int i = 0; i < repeat; i++)
    {
        queue<pair<int, int>> q;
        int num;
        int location;
        cin >> num >> location;

        for (int j = 0; j < num; j++)
        {
            int temp;
            cin >> temp;
            if (j == location)
            {
                q.push(make_pair(temp, 1));
            }
            else
            {
                q.push(make_pair(temp, 0));
            }
        }

        int count = 0;

        while (!q.empty())
        {
            if (higher(q))
            {
                pair<int, int> _temp;
                _temp = q.front();
                q.pop();
                q.push(_temp);
            }
            else
            {
                if (q.front().second == 1)
                {
                    count++;
                    cout << count << endl;
                    break;
                }
                else
                {
                    count++;
                    q.pop();
                }
            }
        }
    }

    return 0;
}