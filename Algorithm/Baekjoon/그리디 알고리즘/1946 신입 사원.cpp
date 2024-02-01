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

vector<pair<int, int>> nums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        for (int i = 0; i < N; ++i)
        {
            int A, B;
            cin >> A >> B;
            nums.push_back(make_pair(A, B));
        }

        sort(nums.begin(), nums.end());

        // 0번은 서류심사 성적이 제일 높기 때문에, 무조건 선발된다. 
        // 1번은 0번보다 서류심사 성적은 낮지만, 면접 성적이 높을 수 있다. 
        // 1번이 0번보다 면접 성적이 높다면, 선발된다. 
        // 2번은 1번보다 서류심사 성적은 낮미나, 면접 성적이 높을 수 있다. 
        // 면접 성적의 커트라인을 0번의 면접 성적에서 1번의 면접 성적으로 변경한다. 
        // 반복
        int maxi = nums[0].second;
        int current = 1;
        for (int i = 1; i < N; ++i)
        {
            if (maxi > nums[i].second)
            {
                maxi = nums[i].second;
                current++;
            }
        }

        cout << current << '\n';

        nums.clear();
    }

    return 0;
}
