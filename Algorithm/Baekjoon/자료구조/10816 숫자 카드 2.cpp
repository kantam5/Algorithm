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

        // upper_bound : ���� Ž������ temp���� ó�� �ʰ��ϴ� ������ �ε����� ��ȯ
        // lower_bound : ���� Ž������ ó������ temp�� �̻��� ������ �ε����� ��ȯ
        // ���� Ž���� ���� �ð� ����
        printf("%lld ", upper_bound(cards.begin(), cards.end(), temp) - lower_bound(cards.begin(), cards.end(), temp));
    }


    return 0;
}