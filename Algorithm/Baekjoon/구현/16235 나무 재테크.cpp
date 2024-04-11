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

int N, M, K;

struct space
{
	int nutrient = 5;
	vector<int> trees;
};

space ground[10][100];
int A[10][100] = { 0, };
int move_x[8] = { -1, -1, -1,  0,  0,  1,  1,  1 };
int move_y[8] = { -1,  0,  1, -1,  1, -1,  0,  1 };

void spring_summer()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			vector<int> aged_trees;

			// ��
			// ���̰� ���� �������� ����
			sort(ground[i][j].trees.begin(), ground[i][j].trees.end());

			int current = 0;
			for (; current < ground[i][j].trees.size(); ++current)
			{
				int current_tree = ground[i][j].trees[current];

				if (current_tree <= ground[i][j].nutrient)
				{
					ground[i][j].nutrient -= current_tree;
					aged_trees.push_back(current_tree + 1);
				}
				else
				{
					// ���� ������ ������ �� ���ٸ� break;
					break;
				}
			}

			// ����
			// break�� �������� ground�� ��������� �߰�
			for (; current < ground[i][j].trees.size(); ++current)
			{
				int current_tree = ground[i][j].trees[current];

				ground[i][j].nutrient += (current_tree / 2);
			}

			// ������ ���� ground�� �߰�
			ground[i][j].trees.clear();

			for (int aged_tree : aged_trees)
			{
				ground[i][j].trees.push_back(aged_tree);
			}
		}
	}
}

void fall()
{
	int temp_ground[10][100] = { 0, };

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int current = 0; current < ground[i][j].trees.size(); ++current)
			{
				int current_tree = ground[i][j].trees[current];

				// ���� �����ϴٸ� ���� ĭ ������ temp_ground�� 1 �߰�
				if (current_tree % 5 == 0)
				{
					for (int dir = 0; dir < 8; ++dir)
					{
						int next_x = i + move_x[dir];
						int next_y = j + move_y[dir];

						if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
						{
							continue;
						}

						temp_ground[next_x][next_y]++;
					}
				}
			}
		}
	}

	// ���ĵ� ���� ground�� �߰�
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			while (temp_ground[i][j] > 0)
			{
				ground[i][j].trees.push_back(1);

				temp_ground[i][j]--;
			}
		}
	}
}

void winter()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			ground[i][j].nutrient += A[i][j];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;

		ground[x - 1][y - 1].trees.push_back(z);
	}

	while (K--)
	{
		spring_summer();
		fall();
		winter();
	}

	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			answer += ground[i][j].trees.size();
		}
	}

	cout << answer;

	return 0;
}