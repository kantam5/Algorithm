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
#include <deque>
#include <climits>

using namespace std;

vector<int> legos;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int x, n;
    while (cin >> x >> n)
    {
        x *= 10'000'000;

        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            legos.push_back(temp);
        }

        sort(legos.begin(), legos.end());

        // 이분 탐색
        // leogs[i]와 들어갈 조각을 이분 탐색한다. 
        // 나머지 조각의 길이는 x - legos[i]이다.
        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            int find_num = x - legos[i];

            int start = i + 1;
            int end = n - 1;
            while (start <= end)
            {
                int mid = (start + end) / 2;

                // find_num과 맞는 레고를 찾았다면 출력
                if (legos[mid] == find_num)
                {
                    cout << "yes " << legos[i] << " " << legos[mid] << '\n';
                    flag = true;
                    break;
                }

                if (legos[mid] < find_num)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }

            if (flag)
            {
                break;
            }
        }

        // 찾지 못 했다면 danger 출력
        if (flag == false)
        {
            cout << "danger" << '\n';
        }

        // 두 포인터
        // 양 옆에서 부터 점차 좁히며 검사
        /*int start = 0;
        int end = n - 1;
        while (start < end)
        {
            int sum = legos[start] + legos[end];

            if (sum == x)
            {
                cout << "yes " << legos[start] << " " << legos[end] << '\n';
                break;
            }

            if (sum < x)
            {
                start++;
            }
            else
            {
                end--;
            }
        }

        if (start >= end)
        {
            cout << "danger" << '\n';
        }*/

        legos.clear();
    }

    return 0;
}