#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <memory.h>
#include <unordered_map>
#include <cmath>

using namespace std;

bool visited[10000];
typedef struct
{
    int n;
    string distance;
} types;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int A;
        int B;
        cin >> A >> B;

        queue<types> bfs;

        bfs.push({ A, "" });
        visited[A] = true;

        while (!bfs.empty())
        {
            auto current = bfs.front();
            bfs.pop();

            // cout << "current.n: " << current.n << " current.distance: " << current.distance << '\n';

            if (current.n == B)
            {
                cout << current.distance << '\n';
                while (!bfs.empty())
                {
                    bfs.pop();
                }
                break;
            }

            // D
            int temp = current.n * 2;
            if (temp > 9999 && !visited[temp % 10000])
            {
                string distance = current.distance;
                distance.push_back('D');
                visited[temp % 10000] = true;
                bfs.push({ temp % 10000, distance });
            }
            else if (temp <= 9999 && !visited[temp])
            {
                string distance = current.distance;
                distance.push_back('D');
                visited[temp] = true;
                bfs.push({ temp , distance });
            }

            // S
            temp = current.n - 1;
            if (temp < 0 && !visited[temp])
            {
                string distance = current.distance;
                distance.push_back('S');
                visited[9999] = true;
                bfs.push({ 9999, distance });
            }
            else if (temp >= 0 && !visited[temp])
            {
                string distance = current.distance;
                distance.push_back('S');
                visited[temp] = true;
                bfs.push({ temp , distance });
            }


            /*temp = current.n;
            int digit_A[4] = { 0 };
            for (int i = 0; i < 4; i++)
            {
                digit_A[i] = temp / (int)pow(10, 3 - i);
                temp %= (int)pow(10, 3 - i);
            }*/

            /*for (int i = 0; i < 4; i++)
            {
                cout << digit_A[i];
            }
            cout << '\n';*/

            // L
            temp = (current.n % 1000) * 10 + current.n / 1000;
            // temp = ((digit_A[1] * 10 + digit_A[2]) * 10 + digit_A[3]) * 10 + digit_A[0];
            if (!visited[temp])
            {
                string distance = current.distance;
                distance.push_back('L');
                visited[temp] = true;
                bfs.push({ temp, distance });
            }

            // R
            temp = (current.n % 10) * 1000 + current.n / 10;
            // temp = ((digit_A[3] * 10 + digit_A[0]) * 10 + digit_A[1]) * 10 + digit_A[2];
            if (!visited[temp])
            {
                string distance = current.distance;
                distance.push_back('R');
                visited[temp] = true;
                bfs.push({ temp, distance });
            }
        }

        memset(visited, false, sizeof(visited));
    }

    return 0;
}