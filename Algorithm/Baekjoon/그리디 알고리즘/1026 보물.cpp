#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    vector<int> v1;
    vector<int> v2;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        v1.push_back(temp);
    }
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        v2.push_back(temp);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), compare);

    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        result += v1[i] * v2[i];
    }

    cout << result;

    return 0;
}