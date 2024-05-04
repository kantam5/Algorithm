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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int answer = 0;

	// 100 �̸��� ���� ��� �Ѽ��̴�.
	if (N < 100)
	{
		answer = N;
	}
	else
	{
		answer = 99;

		// ���ӵ� �ڸ��� ������ ���̰� ��ġ�Ѵٸ� �Ѽ��̴�.
		for (int current = 100; current <= N; ++current)
		{
			int hun = current / 100;
			int ten = (current / 10) % 10;
			int one = current % 10;

			if ((hun - ten) == (ten - one))
			{
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}