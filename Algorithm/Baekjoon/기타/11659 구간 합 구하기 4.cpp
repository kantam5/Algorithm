#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main()
{
	int N;
	int M;
	scanf_s("%d %d", &N, &M);

	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		arr.push_back(temp);
	}

	for (int i = 1; i < arr.size(); i++)
	{
		arr[i] = arr[i] + arr[i - 1];
	}

	int I;
	int J;
	for (int i = 0; i < M; i++)
	{
		scanf_s("%d %d", &I, &J);

		int temp = 0;
		if (I != 1)
		{
			temp = arr[J - 1] - arr[I - 2];
		}
		else if (I == 1)
		{
			temp = arr[J - 1];
		}

		printf("%d\n", temp);
	}

	return 0;
}