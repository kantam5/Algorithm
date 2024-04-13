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

int ground[500];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int H, W;
	cin >> H >> W;

	for (int i = 0; i < W; ++i)
	{
		cin >> ground[i];
	}

	int answer = 0;
	for (int i = 0; i < W; ++i)
	{
		int left_maxi = 0;
		int right_maxi = 0;

		for (int j = i - 1; j >= 0; --j)
		{
			left_maxi = max(left_maxi, ground[j]);
		}

		for (int j = i + 1; j < W; ++j)
		{
			right_maxi = max(right_maxi, ground[j]);
		}

		if (left_maxi > ground[i] && right_maxi > ground[i])
		{
			answer += (min(left_maxi, right_maxi) - ground[i]);
		}
	}

	cout << answer;

	return 0;
}