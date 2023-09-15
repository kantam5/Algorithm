#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 오버플로우 조심
long long cache[101];

long long solution(int n)
{
	if (n == 0 || n == 1 || n == 2)
	{
		return 1;
	}
	else if (n == 3 || n == 4)
	{
		return 2;
	}

	if (cache[n] != 0)
	{
		return cache[n];
	}

	cache[n] = solution(n - 1) + solution(n - 5);
	return cache[n];
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int temp;
		cin >> temp;

		cout << solution(temp - 1) << endl;
	}

	return 0;
}