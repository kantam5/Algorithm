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

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int M;
        int N;
        int x;
        int y;
        cin >> M >> N >> x >> y;
        // cout << M << " " << N << " " << x << " " << y << '\n';

        int LCM;
        {
            int num_1 = max(M, N);
            int num_2 = min(M, N);

            int temp = num_1 % num_2;
            while (temp != 0)
            {
                num_1 = num_2;
                num_2 = temp;
                temp = num_1 % num_2;
            }
            // 최소 공배수
            LCM = (M * N) / num_2;
        }
        bool flag = false;
        for (int i = x; i <= LCM; i += M)
        {
            // i % M = x 확정
            // N만 비교
            int temp = i % N;
            if (temp == 0)
            {
                temp = N;
            }
            if (temp == y)
            {
                flag = true;
                cout << i << '\n';
                break;
            }
        }

        if (flag == false)
        {
            cout << "-1" << '\n';
        }
    }

    return 0;
}