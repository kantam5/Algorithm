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

// MBTI�� �ٸ� �ڸ����� +1
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

        // ��� ���� 32�� �ʰ��ϸ� ������ MBTI�� 3����� ��ġ�� ������ ����� 0
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

            // ��Ʈ��ŷ���� 3����� �߷� �ּҰ��� Ž��
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