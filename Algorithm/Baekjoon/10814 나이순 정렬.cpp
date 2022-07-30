#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<pair<int, string>, int> a, pair<pair<int, string>, int> b)
{
    if (a.first.first < b.first.first)
    {
        return true;
    }
    else if (a.first.first > b.first.first)
    {
        return false;
    }
    else if (a.first.first == b.first.first)
    {
        return a.second < b.second;
    }
}

int main()
{
    int repeat;
    scanf_s("%d", &repeat);

    vector<pair<pair<int, string>, int>> arr;
    for (int i = 0; i < repeat; i++)
    {
        int age;
        string name;
        scanf_s("%d", &age);
        cin >> name;
        // cin >> age >> name;
        arr.push_back(make_pair(make_pair(age, name), i));
    }

    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < repeat; i++)
    {
        printf("%d %s\n", arr[i].first.first, arr[i].first.second.c_str());
        // cout << arr[i].first.first << " " << arr[i].first.second << endl;
    }

    return 0;
}