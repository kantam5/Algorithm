#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        sort(comb.begin(), comb.end());

        for (int i = 0; i < comb.size(); ++i)
        {
            cout << comb[i] << " ";
        }
        cout << '\n';
    }
    else if (depth == arr.size())   // 계속 선택하지 않고 r을 채우지 못한 경우는 바로 return
    {
        return;
    }
    else
    {
        // arr[depth]를 선택한 경우
        // comb의 index자리에 arr의 현재 depth에 해당하는 값이 입력된다.
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);

        // arr[depth]를 선택하지 않은 경우
        // arr의 현재 depth는 넘기고 다음 depth로 넘어간다.
        Combination(arr, comb, r, index, depth + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        int k;
        vector<int> nums;

        cin >> k;
        if (k == 0)
        {
            break;
        }

        for (int i = 0; i < k; ++i)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }

        int r = 6;
        vector<int> answer(6);

        Combination(nums, answer, r, 0, 0);

        cout << '\n';
    }

    return 0;
}