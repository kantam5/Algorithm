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

const int MAX = 1000001;

bool num[MAX];
int answer[MAX];
vector<int> num_v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int maxi = 0;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        num_v.push_back(temp);

        num[temp] = true;                   // �Է����� ���� ���ڸ� true�� ����

        maxi = max(maxi, temp);
    }

    for (int i = 0; i < N; ++i)
    {
        int current_num = num_v[i];
        int temp = 2;
        while (current_num * temp <= maxi)
        {
            if (num[current_num * temp])    // ���� Ȯ���ϴ� ������ ����� �Է����� ���Դٸ�
            {
                answer[current_num]++;
                answer[current_num * temp]--;
            }

            temp++;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << answer[num_v[i]] << " ";
    }

    return 0;
}