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
    else if (depth == arr.size())   // ��� �������� �ʰ� r�� ä���� ���� ���� �ٷ� return
    {
        return;
    }
    else
    {
        // arr[depth]�� ������ ���
        // comb�� index�ڸ��� arr�� ���� depth�� �ش��ϴ� ���� �Էµȴ�.
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);

        // arr[depth]�� �������� ���� ���
        // arr�� ���� depth�� �ѱ�� ���� depth�� �Ѿ��.
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