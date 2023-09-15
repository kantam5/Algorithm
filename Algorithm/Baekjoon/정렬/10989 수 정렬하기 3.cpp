#include <iostream>

using namespace std;

// 시간 제한을 위한 scanf, print
// 메모리 제한을 위해 입력된 수를 카운트해서 작은 수부터 입력된 만큼 출력
// 최대 10000이므로 길이가 10001인 배열의 길이 = 4MB < 8MB

int main()
{
    int length;
    scanf_s("%d", &length);

    int arr[10001] = { 0 };

    for (int i = 0; i < length; i++)
    {
        int temp = 0;
        scanf_s("%d", &temp);

        arr[temp]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}