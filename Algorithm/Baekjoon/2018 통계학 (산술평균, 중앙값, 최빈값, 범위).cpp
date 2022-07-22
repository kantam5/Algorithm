#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;


int main()
{
    int repeat;
    cin >> repeat;

    int mode_arr[8001] = { 0 };

    vector<int> arr;
    for (int i = 0; i < repeat; i++)
    {
        int temp = 0;
        cin >> temp;
        arr.push_back(temp);

        mode_arr[temp + 4000]++;
    }

    // 받은값 정렬
    sort(arr.begin(), arr.end());


    int arithmetic;
    int median;

    // 산술평균
    int temp = 0;
    for (int i = 0; i < repeat; i++)
    {
        temp += arr[i];
    }
    float arithmetic_before = temp / (float)repeat;
    arithmetic = round(arithmetic_before);
    cout << arithmetic << endl;

    // 중앙값
    median = arr[(arr.size() - 1) / 2];
    cout << median << endl;

    // 최빈값
    int max = 0;
    int max_index = 0;
    vector<int> mode_vector;

    for (int i = 0; i < 8001; i++)
    {
        if (max < mode_arr[i])
        {
            max = mode_arr[i];
            max_index = i;
        }
    }
    for (int i = 0; i < 8001; i++)
    {
        if (max == mode_arr[i])
        {
            // max_index는 무조건 들어감
            mode_vector.push_back(i);
        }
    }
    if (mode_vector.size() > 1)
    {
        sort(mode_vector.begin(), mode_vector.end());
        cout << mode_vector[1] - 4000 << endl;
    }
    else
    {
        cout << max_index - 4000 << endl;
    }

    // 범위
    int maxi = *max_element(arr.begin(), arr.end());
    int mini = *min_element(arr.begin(), arr.end());
    cout << maxi - mini;

    return 0;
}