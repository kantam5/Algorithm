#include <iostream>

using namespace std;


int main()
{
    int repeat;
    int length;
    cin >> repeat >> length;

    int* wood = new int[repeat];
    int max = 0;

    for (int i = 0; i < repeat; i++)
    {
        cin >> wood[i];
        if (max < wood[i])
        {
            max = wood[i];
        }
    }

    long long start = 0;
    long long end = max;
    long long mid;
    int result = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;

        long long temp = 0;
        for (int i = 0; i < repeat; i++)
        {
            if (wood[i] - mid > 0)
            {
                temp += wood[i] - mid;
            }
        }

        // 너무 낮게 잘랐을 때
        // 필요한 length만큼은 가져가야 하므로 딱 맞아떨어지지 않아도 조건은 만족할 정도로 높게 자른다.
        if (temp >= length)
        {
            start = mid + 1;
            if (result < mid)
            {
                result = mid;
            }
        }
        // 너무 높이 잘랐을 때
        else
        {
            end = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}