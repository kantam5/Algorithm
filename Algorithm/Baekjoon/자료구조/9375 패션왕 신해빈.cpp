#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 케이스가 필요한것이 아니라 케이스의 수가 중요하다.
int main()
{
    int repeat;
    cin >> repeat;

    for (int i = 0; i < repeat; i++)
    {
        map<string, int> m;

        int n;
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            string temp1;
            string temp2;
            cin >> temp1 >> temp2;

            if (m.find(temp2) == m.end())
            {
                m[temp2] = 1;
            }
            else
            {
                m[temp2]++;
            }
        }

        int result = 1;
        for (auto it : m)
        {
            result *= (it.second + 1);
        }

        cout << result - 1 << endl;
    }

    return 0;
}















#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int result = 0;
void Combination(vector<pair<string, string>> arr, vector<pair<string, string>> comb, vector<string> cloth, int r, int index, int depth)
{
    // r 개를 모두 채웠을 경우
    if (r == 0)
    {
        result++;

        /*for (int i = 0; i < comb.size(); i++)
        {
            cout << comb[i].first << " " << comb[i].second << "  ";
        }
        cout << endl;*/
    }
    else if (depth == arr.size())  // depth == n // 계속 안뽑다가 r 개를 채우지 못한 경우는 이 곳에 걸려야 한다.
    {
        return;
    }
    else
    {
        // 중복되는 옷의 종류가 없을 때 뽑을 수 있다.
        sort(cloth.begin(), cloth.end());
        if (!binary_search(cloth.begin(), cloth.end(), arr[depth].second))
        {
            // arr[depth] 를 뽑은 경우
            comb[index] = arr[depth];

            vector<string> temp;
            for (int i = 0; i < cloth.size(); i++)
            {
                temp.push_back(cloth[i]);
            }
            temp.push_back(arr[depth].second);
            Combination(arr, comb, temp, r - 1, index + 1, depth + 1);
        }

        // arr[depth] 를 뽑지 않은 경우
        Combination(arr, comb, cloth, r, index, depth + 1);
    }
}

int main()
{
    int repeat;
    scanf("%d", &repeat);

    for (int i = 0; i < repeat; i++)
    {
        int n;
        cin >> n;
        vector<pair<string, string>> arr;
        for (int i = 0; i < n; i++)
        {
            char cloth_name[21];
            char cloth[21];
            scanf("%s %s", cloth_name, cloth);
            string temp1 = cloth_name;
            string temp2 = cloth;

            arr.push_back(make_pair(temp1, temp2));
        }

        for (int i = 1; i <= n; i++)
        {
            vector<pair<string, string>> comb(i);

            vector<string> arr2;

            Combination(arr, comb, arr2, i, 0, 0);
        }

        printf("%d\n", result);
        result = 0;
    }


    return 0;
}