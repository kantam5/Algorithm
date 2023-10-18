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

const int MAX = 4'000'001;

bool prime[MAX];

// �����佺�׳׽��� ü
// N������ �� �� �Ҽ��� true�� ǥ��
void eratosthenes(int N)
{
    memset(prime, false, sizeof(prime));

    for (int i = 2; i <= N; ++i)
    {
        prime[i] = true;
    }

    for (int i = 2; i * i <= N; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N;
    int answer = 0;
    cin >> N;

    eratosthenes(N);

    int start = 2;
    int end = 2;

    while (start <= end)
    {
        int sum = 0;

        // start���� end���� �Ҽ� ��
        for (int i = start; i <= end; ++i)
        {
            if (prime[i])
            {
                sum += i;
            }
        }

        if (sum == N)
        {
            answer++;
        }

        // N ���϶�� end�� ���� �Ҽ����� ����
        if (sum <= N)
        {
            end++;
            while (!prime[end])
            {
                end++;
            }
        }
        // N �ʰ���� start�� ���� �Ҽ����� ����
        else
        {
            start++;
            while (!prime[start])
            {
                start++;
            }
        }
    }

    cout << answer;

    return 0;
}