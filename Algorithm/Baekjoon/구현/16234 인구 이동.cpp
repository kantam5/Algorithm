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
#include <sstream>
#include <cstdlib>

using namespace std;

int nums[50][50];
vector<pair<int, int>> open[50][50];
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };
bool visited[50][50];
vector<pair<int, int>> guild;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, R;
    cin >> N >> L >> R;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> nums[i][j];
        }
    }

    int answer = 0;
    while (true)
    {
        memset(visited, false, sizeof(visited));

        bool flag = false;

        for (int x = 0; x < N; ++x)
        {
            for (int y = 0; y < N; ++y)
            {
                // 이미 연합 시도를 했거나, 연합을 이루웠었던 칸은 접근하지 않는다.
                if (visited[x][y] == true)
                {
                    continue;
                }

                guild.clear();

                queue<pair<int, int>> q;
                q.push(make_pair(x, y));
                guild.push_back(make_pair(x, y));
                visited[x][y] = true;
                int sum = nums[x][y];

                // bfs로 현재 칸과 인접하면서, 조건에 맞는 칸을 guild에 넣는다.
                while (!q.empty())
                {
                    int current_x = q.front().first;
                    int current_y = q.front().second;
                    q.pop();

                    for (int i = 0; i < 4; ++i)
                    {
                        int next_x = current_x + move_x[i];
                        int next_y = current_y + move_y[i];
                        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || visited[next_x][next_y])
                        {
                            continue;
                        }

                        int diff = abs(nums[current_x][current_y] - nums[next_x][next_y]);
                        if (L <= diff && diff <= R)
                        {
                            visited[next_x][next_y] = true;
                            q.push(make_pair(next_x, next_y));
                            guild.push_back(make_pair(next_x, next_y));
                            sum += nums[next_x][next_y];
                        }
                    }
                }

                // 연합을 이룰 수 있다면, 인구를 조절한다.
                if (guild.size() > 1)
                {
                    flag = true;

                    int avg = sum / guild.size();
                    for (int i = 0; i < guild.size(); ++i)
                    {
                        nums[guild[i].first][guild[i].second] = avg;
                    }
                }
            }
        }

        // flag가 false라면 탈출, true라면 하루 더
        if (!flag)
        {
            break;
        }
        else
        {
            answer++;
        }
    }

    cout << answer;

    return 0;
}
