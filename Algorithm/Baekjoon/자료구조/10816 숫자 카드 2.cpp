#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num1;
    scanf_s("%d", &num1);

    vector<int> cards;
    for (int i = 0; i < num1; i++)
    {
        int temp;
        scanf_s("%d", &temp);
        cards.push_back(temp);
    }
    sort(cards.begin(), cards.end());

    int num2;
    scanf_s("%d", &num2);
    for (int i = 0; i < num2; i++)
    {
        int temp;
        scanf_s("%d", &temp);

        // upper_bound : 이진 탐색으로 temp값을 처음 초과하는 원소의 인덱스를 반환
        // lower_bound : 이진 탐색으로 처음으로 temp값 이상인 원소의 인덱스를 반환
        // 이진 탐색을 통한 시간 절약
        printf("%lld ", upper_bound(cards.begin(), cards.end(), temp) - lower_bound(cards.begin(), cards.end(), temp));
    }


    return 0;
}