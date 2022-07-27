#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int num;
    cin >> num;

    queue<int> arr;
    for (int i = 0; i < num; i++)
    {
        arr.push(i + 1);
    }

    while (arr.size() != 1)
    {
        arr.pop();

        int temp = arr.front();
        arr.pop();
        arr.push(temp);
    }

    cout << arr.front() << endl;

    return 0;
}