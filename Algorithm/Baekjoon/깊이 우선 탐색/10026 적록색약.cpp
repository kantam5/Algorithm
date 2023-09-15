#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int result_count = 0;

vector<int> graph[10001];
vector<int> graph_[10001];
bool visited[10001];

// current������ �����Ͽ� graph�� ���� �켱 Ž��
void dfs(vector<int> _graph[], int current, int n)
{
    result_count++;
    visited[current] = true;

    for (int next : _graph[current])
    {
        if (!visited[next])
        {
            dfs(_graph, next, n);
        }
    }
}

vector<pair<char, int>> ground[101];
vector<pair<char, int>> ground_[101];
int N;

// �����¿�� ���� ���� ��带 �����Ͽ� �׷��� ����
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void create_graph(int y, int x, vector<pair<char, int>> _ground[], vector<int> _graph[])
{
    for (int i = 0; i < 4; i++)
    {
        int new_y = y + dy[i];
        int new_x = x + dx[i];
        if (new_y < 0 || N <= new_y)
        {
            continue;
        }
        if (new_x < 0 || N <= new_x)
        {
            continue;
        }

        // ������ ���ڳ��� ������ üũ
        if (_ground[y][x].first == _ground[new_y][new_x].first)
        {
            _graph[_ground[y][x].second].push_back(_ground[new_y][new_x].second);
        }
    }

    return;
}

int main()
{
    cin >> N;

    int node_count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char temp;
            cin >> temp;
            ground[i].push_back(make_pair(temp, node_count));
            if (temp == 'G')
            {
                ground_[i].push_back(make_pair('R', node_count));
            }
            else
            {
                ground_[i].push_back(make_pair(temp, node_count));
            }
            node_count++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            create_graph(i, j, ground, graph);
        }
    }

    if (N == 1)
    {
        cout << "1 1";
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            create_graph(i, j, ground_, graph_);
        }
    }

    // ���� ������ ������ ����� ���� ĭ�� ���� ground_area
    int ground_area = N * N;
    int result = 0;
    int result_ = 0;

    for (int i = 0; i < N * N; i++)
    {
        dfs(graph, i, i);
        if (result_count > 1)
        {
            ground_area -= result_count;
            result++;
        }
        result_count = 0;
    }
    result += ground_area;

    ground_area = N * N;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N * N; i++)
    {
        dfs(graph_, i, i);
        if (result_count > 1)
        {
            ground_area -= result_count;
            result_++;
        }
        result_count = 0;
    }
    result_ += ground_area;

    cout << result << " " << result_;

    return 0;
}
