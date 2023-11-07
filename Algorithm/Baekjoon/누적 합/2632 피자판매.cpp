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

vector<int> A;
vector<int> A_parts;
vector<int> B;
vector<int> B_parts;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int P;
    int m, n;
    cin >> P >> m >> n;

    int sum_A = 0;
    for (int i = 0; i < m; ++i)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);

        sum_A += temp;
    }
    int sum_B = 0;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        B.push_back(temp);

        sum_B += temp;
    }

    // 3�� for���� �ð��ʰ�
    // A�� i���� (i + j) ���������� ���� A_parts�� �߰��Ѵ�.
    // 0���� m���� ���� �ߺ��� �� ������ ���� �߰��Ѵ�.
    for (int i = 0; i < m; ++i)
    {
        int temp = 0;
        for (int j = 0; j < m - 1; ++j)
        {
            temp += A[(i + j) % m];
            A_parts.push_back(temp);
        }
    }
    A_parts.push_back(0);
    A_parts.push_back(sum_A);

    // B�� i���� (i + j) ���������� ���� B_parts�� �߰��Ѵ�.
    // 0���� m���� ���� �ߺ��� �� ������ ���� �߰��Ѵ�.
    for (int i = 0; i < n; ++i)
    {
        int temp = 0;
        for (int j = 0; j < n - 1; ++j)
        {
            temp += B[(i + j) % n];
            B_parts.push_back(temp);
        }
    }
    B_parts.push_back(0);
    B_parts.push_back(sum_B);

    // ���� Ž���� ���� ����
    sort(B_parts.begin(), B_parts.end());

    // upper_bound, lower_bound�� A_parts[i]�� �´� B_parts�� ���� ã�´�.
    int answer = 0;
    for (int i = 0; i < A_parts.size(); ++i)
    {
        int diff = P - A_parts[i];
        answer += upper_bound(B_parts.begin(), B_parts.end(), diff)
            - lower_bound(B_parts.begin(), B_parts.end(), diff);
    }

    cout << answer;

    return 0;
}