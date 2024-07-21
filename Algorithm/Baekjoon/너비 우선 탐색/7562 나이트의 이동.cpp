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
#include <unordered_set>

using namespace std;

int T;
int I;
// visited 배열이 아닌 int로 count와 방문 여부를 동시 관리
int moveCount[300][300];

int moveX[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int moveY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	memset(moveCount, 0, sizeof(moveCount));

	while (T--)
	{
		int startX, startY, destX, destY;
		queue<pair<int, int>> q;

		cin >> I;
		cin >> startX >> startY >> destX >> destY;

		q.push(make_pair(startX, startY));

		while (false == q.empty())
		{
			int currentX = q.front().first;
			int currentY = q.front().second;
			q.pop();

			if (destX == currentX && destY == currentY)
			{
				cout << moveCount[currentX][currentY] << '\n';
				break;
			}

			for (int i = 0; i < 8; ++i)
			{
				int nextX = currentX + moveX[i];
				int nextY = currentY + moveY[i];

				// moveCount가 0이 아닌 경우는 이미 방문한 칸이므로 continue 처리
				if (nextX < 0 || nextX >= I || nextY < 0 || nextY >= I || 0 != moveCount[nextX][nextY])
				{
					continue;
				}

				q.push(make_pair(nextX, nextY));
				moveCount[nextX][nextY] = moveCount[currentX][currentY] + 1;
			}
		}

		memset(moveCount, 0, sizeof(moveCount));
	}

	return 0;
}