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

int A[1001];
vector<int> sum_A;
int B[1001];
vector<int> sum_B;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int T, n, m;
    long long answer = 0;
    cin >> T;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> B[i];
    }

    // A���� ���� �� �ִ� ��� �� �迭�� ���� sum_A�� ����
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += A[j];
            sum_A.push_back(sum);
        }
    }

    // B���� ���� �� �ִ� ��� �� �迭�� ���� sum_B�� ����
    for (int i = 0; i < m; ++i)
    {
        int sum = 0;
        for (int j = i; j < m; ++j)
        {
            sum += B[j];
            sum_B.push_back(sum);
        }
    }

    // �̺� Ž���� ���� ����
    sort(sum_B.begin(), sum_B.end());

    // upper_bound�� diff�� �ʰ��ϴ� ���� ù �ε����� ��ȯ
    // lower_bound�� diff �̻��� ���� ù �ε����� ��ȯ
    for (int i = 0; i < sum_A.size(); ++i)
    {
        int diff = T - sum_A[i];
        answer += upper_bound(sum_B.begin(), sum_B.end(), diff)
            - lower_bound(sum_B.begin(), sum_B.end(), diff);
    }

    cout << answer;

    return 0;
}