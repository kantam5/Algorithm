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

int getDivisorCount(int num)
{
	int count = 0;

	for (int i = 1; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			if (i != sqrt(num))
			{
				count += 2;
			}
			else
			{
				count++;
			}
		}
	}

	return count;
}

int solution(int left, int right)
{
	int answer = 0;

	for (int i = left; i <= right; ++i)
	{
		int divisorCount = getDivisorCount(i);

		if (divisorCount % 2 == 0)
		{
			answer += i;
		}
		else
		{
			answer -= i;
		}
	}

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << solution(10, 15);

	return 0;
}