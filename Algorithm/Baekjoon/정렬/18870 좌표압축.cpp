#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <memory.h>

using namespace std;

int main()
{
	int N;
	scanf_s("%d", &N);

	vector<int> arr;
	vector<int> temp_arr;
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		arr.push_back(temp);
		temp_arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < N; i++)
	{
		// lower_bound는 시간복잡도가 O(log N)
		printf("%d ", lower_bound(arr.begin(), arr.end(), temp_arr[i]) - arr.begin());
	}
	printf("\n");

	return 0;
}