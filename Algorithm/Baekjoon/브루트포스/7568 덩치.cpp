#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int repeat;
    cin >> repeat;

    vector<pair<int, int>> body;
    vector<int> build;

    for (int i = 0; i < repeat; i++)
    {
        int height;
        int weight;
        cin >> height >> weight;

        body.push_back(make_pair(height, weight));
    }

    // body[i]보다 덩치가 큰 body를 build에 push
    for (int i = 0; i < body.size(); i++)
    {
        int temp = 0;
        for (int j = 0; j < body.size(); j++)
        {
            if (body[i].first < body[j].first && body[i].second < body[j].second)
            {
                temp++;
            }
        }
        build.push_back(temp);
    }

    for (int i = 0; i < build.size(); i++)
    {
        cout << build[i] + 1 << " ";
    }

    return 0;
}