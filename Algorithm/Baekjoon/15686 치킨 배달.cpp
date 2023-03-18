#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <memory.h>
#include <unordered_map>
#include <cmath>
#include <deque>
#include <climits>

using namespace std;

int N, M;
int board[51][51];
int mini = INT_MAX;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> arr;

void solution()
{
    int total_distance = 0;
    for (int i = 0; i < house.size(); i++)
    {
        int distance = INT_MAX;
        for (int j = 0; j < arr.size(); j++)
        {
            int temp = abs(house[i].first - arr[j].first) + abs(house[i].second - arr[j].second);
            if (distance > temp)
            {
                distance = temp;
            }
        }
        total_distance += distance;
    }
    if (mini > total_distance)
    {
        mini = total_distance;
    }
}

bool isInArr(pair<int, int> element)
{
    for (pair<int, int> arrElement : arr)
    {
        if (arrElement.first == element.first && arrElement.second == element.second)
        {
            return true;
        }
    }
    return false;
}

void back(int source)
{
    if (M == arr.size())
    {
        solution();
        /*for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i].first << " " << arr[i].second << endl;
        }
        cout << endl;*/
    }

    for (int i = source; i < chicken.size(); i++)
    {
        if (!isInArr(chicken[i]))
        {
            arr.push_back(chicken[i]);
            back(i + 1);
            arr.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                house.push_back(make_pair(i, j));
            }
            if (board[i][j] == 2)
            {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    back(0);

    cout << mini << endl;

    return 0;
}