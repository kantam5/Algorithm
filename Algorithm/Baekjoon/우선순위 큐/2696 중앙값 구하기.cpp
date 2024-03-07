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
#include <sstream>
#include <cstdlib>

using namespace std;

priority_queue<int> smaller;
priority_queue<int, vector<int>, greater<int>> bigger;
vector<int> nums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int M;
        cin >> M;

        while (!smaller.empty())
        {
            smaller.pop();
        }
        while (!bigger.empty())
        {
            bigger.pop();
        }
        nums.clear();

        for (int i = 1; i <= M; ++i)
        {
            int num;
            cin >> num;

            nums.push_back(num);
        }

        if (nums.size() % 2 == 1)
        {
            cout << (nums.size() / 2) + 1;
        }
        else
        {
            cout << nums.size() / 2;
        }
        cout << '\n';

        for (int i = 1; i <= M; ++i)
        {
            int num = nums[i - 1];

            if (smaller.empty())
            {
                smaller.push(num);
            }
            else if (smaller.size() == bigger.size())
            {
                smaller.push(num);
            }
            else
            {
                bigger.push(num);
            }

            if (!smaller.empty() && !bigger.empty() && smaller.top() > bigger.top())
            {
                int a = smaller.top();
                smaller.pop();
                int b = bigger.top();
                bigger.pop();

                bigger.push(a);
                smaller.push(b);
            }

            if (i % 2 == 1)
            {
                cout << smaller.top() << " ";
            }
            if (i % 20 == 0)
            {
                cout << '\n';
            }
        }

        cout << '\n';
    }

    return 0;
}
