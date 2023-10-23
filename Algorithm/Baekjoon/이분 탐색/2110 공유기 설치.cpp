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

    // 공유기를 설치할 수 있는 최소 거리인 1
    // 최대 거리인 첫 집에서 마지막 집 까지의 거리
    // 공유기를 설치할 간격을 줄여나가면서 이분 탐색을 진행한다. 
    // 설치한 공유기의 수가 N을 충족한다면 answer를 갱신한다.
    int start = 1;
    int end = house[N - 1] - house[0];
    int answer = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // 첫번째 집은 무조건 설치한 상태로 진행한다.
        int router = 1;
        int pre_house = house[0];

        // 가장 최근에 설치한 집과의 거리가 mid보다 클 경우
        // pre_house를 갱신하고 공유기 설치수를 증가시킨다.
        for (int i = 1; i < N; ++i)
        {
            if (house[i] - pre_house >= mid)
            {
                router++;
                pre_house = house[i];
            }
        }

        // C보다 많은 공유기를 설치했다면
        // start를 늘려서 설치할 거리를 늘린다.
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