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

	// 100 미만의 수는 모두 한수이다.
	if (N < 100)
	{
		answer = N;
	}
	else
	{
		answer = 99;

		// 연속된 자리수 사이의 차이가 일치한다면 한수이다.
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