#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int repeat;
    int length;
    cin >> repeat >> length;

    int* line = new int[repeat];
    int maxi = 0;

    for (int i = 0; i < repeat; i++)
    {
        cin >> line[i];
        if (maxi < line[i])
        {
            maxi = line[i];
        }
    }

    // long long
    long long start = 1;
    long long end = maxi;
    long long mid = 0;
    int result = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;

        // 잘랐을 때, 몇 개의 랜선이 나올 수 있는가
        int temp = 0;
        for (int i = 0; i < repeat; i++)
        {
            temp += line[i] / mid;
        }

        // 잘랐을 때의 랜선이 지정한 개수보다 많다면 start를 좁힌다. 
        // start > end 까지 계속해서 result를 갱신시켜서 최대값을 찾는다. 
        if (temp >= length)
        {
            start = mid + 1;
            if (result < mid)
            {
                result = mid;
            }
        }
        // 잘랐을 때의 랜선이 지정한 개수보다 작다면 end를 좁힌다.
        else
        {
            end = mid - 1;
        }
    }

    cout << result;

    delete[] line;

    return 0;
}