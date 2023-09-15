#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <memory.h>
#include <unordered_map>

using namespace std;

int cache[1000001];

int solution(int n)
{
	if (cache[n] != 0)
	{
		return cache[n];
	}
	else if (n == 1)
	{
		return 0;
	}

	// 1�� ������ ������ ���� ��� ���ǵ��� ���ؾ� �Ѵ�. 
	// ������ 3���� �����°� ������ �ƴϴ�. 
	cache[n] = 1 + solution(n - 1);
	if (n % 3 == 0)
	{
		cache[n] = min(cache[n], 1 + solution(n / 3));
	}
	if (n % 2 == 0)
	{
		cache[n] = min(cache[n], 1 + solution(n / 2));
	}

	return cache[n];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	cout << solution(N) << endl;

	return 0;

}