#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N, C;
    vector<int> house;
    cin >> N >> C;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        house.push_back(temp);
    }

    sort(house.begin(), house.end());

    // �����⸦ ��ġ�� �� �ִ� �ּ� �Ÿ��� 1
    // �ִ� �Ÿ��� ù ������ ������ �� ������ �Ÿ�
    // �����⸦ ��ġ�� ������ �ٿ������鼭 �̺� Ž���� �����Ѵ�. 
    // ��ġ�� �������� ���� N�� �����Ѵٸ� answer�� �����Ѵ�.
    int start = 1;
    int end = house[N - 1] - house[0];
    int answer = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // ù��° ���� ������ ��ġ�� ���·� �����Ѵ�.
        int router = 1;
        int pre_house = house[0];

        // ���� �ֱٿ� ��ġ�� ������ �Ÿ��� mid���� Ŭ ���
        // pre_house�� �����ϰ� ������ ��ġ���� ������Ų��.
        for (int i = 1; i < N; ++i)
        {
            if (house[i] - pre_house >= mid)
            {
                router++;
                pre_house = house[i];
            }
        }

        // C���� ���� �����⸦ ��ġ�ߴٸ�
        // start�� �÷��� ��ġ�� �Ÿ��� �ø���.
        if (router >= C)
        {
            start = mid + 1;
            answer = max(answer, mid);
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}