#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <climits>

using namespace std;

vector<string> MBTIs;
vector<string> mini_MBTIs;
int mini = INT_MAX;

// MBTI가 다른 자리마다 +1
int CalcDistance()
{
    int distance = 0;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = i + 1; j < 3; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                if (mini_MBTIs[i][k] != mini_MBTIs[j][k])
                {
                    distance++;
                }
            }
        }
    }

    return distance;
}

void BackTracking(int index)
{
    if (mini_MBTIs.size() == 3)
    {
        mini = min(mini, CalcDistance());

        return;
    }

    for (size_t i = index + 1; i < MBTIs.size(); ++i)
    {
        mini_MBTIs.push_back(MBTIs[i]);
        BackTracking(i);
        mini_MBTIs.pop_back();
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        // 사람 수가 32를 초과하면 무조건 MBTI가 3사람은 겹치기 때문에 결과는 0
        if (N > 32)
        {
            string temp;
            while (N--)
            {
                cin >> temp;
            }

            cout << 0 << endl;
        }
        else
        {
            while (N--)
            {
                string temp;
                cin >> temp;

                MBTIs.push_back(temp);
            }

            // 백트래킹으로 3사람을 추려 최소값을 탐색
            for (size_t i = 0; i < MBTIs.size(); ++i)
            {
                mini_MBTIs.push_back(MBTIs[i]);
                BackTracking(i);
                mini_MBTIs.pop_back();
            }

            cout << mini << endl;

            MBTIs.clear();
            mini_MBTIs.clear();
            mini = INT_MAX;
        }
    }

    return 0;
}