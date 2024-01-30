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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    // �ִ��� ���� �ڿ������� ���ϸ鼭 �������� N�� ���� �� �ֵ��� �� �´� ���� ���Ѵ�.
    // 1 + 2 + 3 + ... + (N�� ����� ��)
    long long sum = 0;
    long long current = 1;
    int answer = 0;
    while (sum <= N)
    {
        sum += current;
        current++;

        answer++;
    }

    cout << answer - 1;

    return 0;
}
