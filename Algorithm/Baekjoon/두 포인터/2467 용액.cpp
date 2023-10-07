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

int main()
{
    int N;
    vector<int> v;
    vector<int> answer;

    cin >> N;
    v.resize(N);
    answer.resize(2);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    int start = 0;
    int end = N - 1;
    answer[0] = v[start];
    answer[1] = v[end];

    // vector�� ���ʿ��� �ٰ����鼭 start�� end�� �Ѿ �� ���� �˻�
    while (start < end)
    {
        // ���� start�� end�� ���� ������ answer�� ���񰪺��� �۴ٸ� ����
        if (abs(answer[0] + answer[1]) > abs(v[start] + v[end]))
        {
            answer[0] = v[start];
            answer[1] = v[end];
        }

        // ���� 0���� �۴ٸ� ������ ������ ũ�Ƿ� start�� 1����
        if (v[start] + v[end] < 0)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    cout << answer[0] << " " << answer[1];

    return 0;
}