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

        // �߶��� ��, �� ���� ������ ���� �� �ִ°�
        int temp = 0;
        for (int i = 0; i < repeat; i++)
        {
            temp += line[i] / mid;
        }

        // �߶��� ���� ������ ������ �������� ���ٸ� start�� ������. 
        // start > end ���� ����ؼ� result�� ���Ž��Ѽ� �ִ밪�� ã�´�. 
        if (temp >= length)
        {
            start = mid + 1;
            if (result < mid)
            {
                result = mid;
            }
        }
        // �߶��� ���� ������ ������ �������� �۴ٸ� end�� ������.
        else
        {
            end = mid - 1;
        }
    }

    cout << result;

    delete[] line;

    return 0;
}