#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main()
{
    int N;
    int M;

    scanf_s("%d %d", &N, &M);

    map<string, string> _map;
    vector<pair<string, string>> arr;
    for (int i = 0; i < N; i++)
    {
        string temp_1;
        string temp_2;
        cin >> temp_1 >> temp_2;
        _map.insert(make_pair(temp_1, temp_2));
    }

    for (int i = 0; i < M; i++)
    {
        string temp;
        cin >> temp;

        printf("%s\n", _map[temp].c_str());

        /*auto it = _map.find(temp);
        printf("%s\n", it->second.c_str());*/
    }

    return 0;
}