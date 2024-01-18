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

vector<int> nums;

int gcd(int A, int B)
{
    if (A < B)
    {
        swap(A, B);
    }

    int temp;
    while (B != 0)
    {
        temp = A % B;
        A = B;
        B = temp;
    }

    return A;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;

        nums.push_back(temp);
    }

    // ���μ� ������ ������ �ּҰ������ ���Ѵ�.
    int GCD = nums[1] - nums[0];
    for (int i = 1; i < nums.size() - 1; ++i)
    {
        GCD = gcd(GCD, nums[i + 1] - nums[i]);
    }

    // ù ���μ��� ������ ���μ� ������ �Ÿ�
    int range = nums[N - 1] - nums[0];

    // range���̿� GCD�� �������� ���� �� �ִ� ���μ��� ��
    int answer = (range / GCD) - 1;
    // range �� ���� ���μ��� ������ �̹� �ɾ��� �ִ� ���μ��� ����.
    answer -= (N - 2);

    cout << answer;

    return 0;
}
