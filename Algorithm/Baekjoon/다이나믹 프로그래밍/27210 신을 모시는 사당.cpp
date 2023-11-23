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

int nums[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    int answer = 0;

    // ��ĥ�� ������ �迭�� ù ������ ������ ���� �������� ��츦 ������ �����Ѵ�. 
    // ������ �������� ������ �迭������ ������ ���� left
    int left = 0;
    // �������� �������� ������ �迭������ ������ ���� right
    int right = 0;

    for (int i = 0; i < N; ++i)
    {
        // ���� ������ �迭�ȿ� ���� �ִٰ� �����Ѵ�. 
        // ���� ������ ������ ��쿡�� left�� 1 �����ϰ�, right�� 1 �����Ѵ�.
        if (nums[i] == 1)
        {
            left++;
            right--;
        }
        // ���� ������ �������� ��쿡�� left�� 1 �����ϰ�, right�� 1 �����Ѵ�.
        else
        {
            left--;
            right++;
        }
        // ���� �迭�� ������ ���� 0�̸��̶�� ���� �迭�� ������.
        left = left < 0 ? 0 : left;
        right = right < 0 ? 0 : right;

        // ���� �迭 2���� ������ ���� �ִ밪�� ���̴�.
        int maxi = max(left, right);
        answer = max(answer, maxi);
    }

    cout << answer;

    return 0;
}