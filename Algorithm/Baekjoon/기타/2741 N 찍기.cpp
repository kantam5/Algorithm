#include <iostream>

using namespace std;

int main()
{
    // 시간초과는 scanf, printf
    int num = 0;
    int temp = 0;

    scanf_s("%d", &num);

    for (;;)
    {
        temp++;
        printf("%d\n", temp);
        if (temp == num)
        {
            break;
        }
    }

    return 0;
}