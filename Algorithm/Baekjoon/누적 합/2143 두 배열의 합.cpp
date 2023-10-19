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

    // A에서 얻을 수 있는 모든 부 배열의 합을 sum_A에 저장
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += A[j];
            sum_A.push_back(sum);
        }
    }

    // B에서 얻을 수 있는 모든 부 배열의 합을 sum_B에 저장
    for (int i = 0; i < m; ++i)
    {
        int sum = 0;
        for (int j = i; j < m; ++j)
        {
            sum += B[j];
            sum_B.push_back(sum);
        }
    }

    // 이분 탐색을 위해 정렬
    sort(sum_B.begin(), sum_B.end());

    // upper_bound는 diff를 초과하는 값의 첫 인덱스를 반환
    // lower_bound는 diff 이상의 값의 첫 인덱스를 반환
    for (int i = 0; i < sum_A.size(); ++i)
    {
        int diff = T - sum_A[i];
        answer += upper_bound(sum_B.begin(), sum_B.end(), diff)
            - lower_bound(sum_B.begin(), sum_B.end(), diff);
    }

    cout << answer;

    return 0;
}