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

	// 예산의 범위는 1부터 최대 예산요청액
	int start = 1;
	int end = maxi;
	int answer = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		int sum = 0;

		// 현재 합계 계산
		for (int i = 0; i < N; ++i)
		{
			// 상한액만큼이 현재 sum에 들어간다.
			sum += min(mid, nums[i]);
		}

		// 현재 합계와 총 예산을 비교
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