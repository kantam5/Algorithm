#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include<cstring>

using namespace std;

int ground[500][500] = { -1 };

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

int main()
{
    // 현재 최대 땅 높이로 맞췄을 때, -> 한 칸씩 깎았을 때,
    // 그 다음 그 깎은 높이에서 채울 수 있는지 비교, -> 한 칸 깎고
    int N;
    int M;
    int B;
    scanf_s("%d %d %d", &N, &M, &B);

    vector<pair<int, int>> result;

    int maxi = -1;
    int max_i = -1;
    int max_j = -1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> ground[i][j];
            if (maxi < ground[i][j])
            {
                maxi = ground[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    while (maxi >= 0)
    {
        int fill_count = 0;
        int rest_block = B;
        int time = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (maxi < ground[i][j])
                {
                    rest_block += ground[i][j] - maxi;
                }
                if (maxi > ground[i][j])
                {
                    fill_count += maxi - ground[i][j];
                }
            }
        }
        time += 2 * (rest_block - B);
        if (rest_block >= fill_count)
        {
            time += fill_count;
            result.push_back(make_pair(time, maxi));
            cout << "maxi : " << maxi << " | time : " << time << " | fill_count : " << fill_count << " | rest_block : " << rest_block << endl;
        }

        maxi--;
    }

    sort(result.begin(), result.end(), compare);

    printf("%d %d", result[0].first, result[0].second);

    return 0;
}