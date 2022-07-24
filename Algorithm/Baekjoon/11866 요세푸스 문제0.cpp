#include <iostream>
#include <queue>

using namespace std;


int main()
{
    int n;
    int k;
    cin >> n >> k;

    queue<int> arr;
    queue<int> result;

    for (int i = 0; i < n; i++)
    {
        arr.push(i + 1);
    }

    while (!arr.empty())
    {
        // k - 1�� pop�� ���� �ٽ� push
        for (int i = 0; i < k - 1; i++)
        {
            int temp = arr.front();
            arr.pop();
            arr.push(temp);
        }
        // �� �� pop�� ���� result��
        int temp = arr.front();
        arr.pop();
        result.push(temp);
    }


    cout << "<";
    for (int i = 0; i < n; i++)
    {
        cout << result.front();
        result.pop();
        if (i == n - 1)
        {
            break;
        }
        cout << ", ";
    }
    cout << ">";

    return 0;
}