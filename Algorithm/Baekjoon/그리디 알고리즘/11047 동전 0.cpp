#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    int K;
    cin >> N >> K;

    vector<int> coins;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }

    // 먼저 현재 금액이 K를 만족하는지 체크한다. 
    // 만약 만족하지 않다면 가장 큰 동전부터 넣는다. 
    // 그 때, K를 초과한다면 그 동전보다 한 단계 작은 동전을 넣는다. 
    // 이를 반복한다. 
    sort(coins.begin(), coins.end(), compare);

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        while (K - coins[i] >= 0)
        {
            K -= coins[i];
            count++;
        }
    }

    cout << count << endl;

    return 0;
}