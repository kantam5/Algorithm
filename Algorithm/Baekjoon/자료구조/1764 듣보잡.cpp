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
	int M;
	cin >> N >> M;

	vector<string> listen_arr;
	vector<string> see_arr;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		listen_arr.push_back(temp);
	}
	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		see_arr.push_back(temp);
	}

	sort(listen_arr.begin(), listen_arr.end());
	sort(see_arr.begin(), see_arr.end());

	vector<string> result;
	if (N <= M)
	{
		for (int i = 0; i < N; i++)
		{
			if (binary_search(see_arr.begin(), see_arr.end(), listen_arr[i]))
			{
				result.push_back(listen_arr[i]);
			}
		}
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			if (binary_search(listen_arr.begin(), listen_arr.end(), see_arr[i]))
			{
				result.push_back(see_arr[i]);
			}
		}
	}

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}