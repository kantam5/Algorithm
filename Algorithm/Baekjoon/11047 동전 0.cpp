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

    // ���� ���� �ݾ��� K�� �����ϴ��� üũ�Ѵ�. 
    // ���� �������� �ʴٸ� ���� ū �������� �ִ´�. 
    // �� ��, K�� �ʰ��Ѵٸ� �� �������� �� �ܰ� ���� ������ �ִ´�. 
    // �̸� �ݺ��Ѵ�. 
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