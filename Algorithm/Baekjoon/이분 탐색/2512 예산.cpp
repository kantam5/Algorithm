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

int nums[10'000];
int M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int maxi = 0;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];

		maxi = max(maxi, nums[i]);
	}

	cin >> M;

	// ������ ������ 1���� �ִ� �����û��
	int start = 1;
	int end = maxi;
	int answer = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		int sum = 0;

		// ���� �հ� ���
		for (int i = 0; i < N; ++i)
		{
			// ���Ѿ׸�ŭ�� ���� sum�� ����.
			sum += min(mid, nums[i]);
		}

		// ���� �հ�� �� ������ ��
		if (sum > M)
		{
			end = mid - 1;
		}
		else
		{
			answer = mid;
			start = mid + 1;
		}
	}

	cout << answer;

	return 0;
}