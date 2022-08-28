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

bool compare(pair<int, int> a, pair<int, int> b)
{
	/*if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
	{
		return a.first < b.first;
	}*/
	if (a.second - a.first == b.second - b.first)
	{
		return a.first < b.first;
	}
	return a.second - a.first < b.second - b.first;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> arr;
	for (int i = 0; i < N; i++)
	{
		int temp1;
		int temp2;
		cin >> temp1 >> temp2;

		arr.push_back(make_pair(temp1, temp2));
	}

	/*sort(arr.begin(), arr.end(), compare);
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first << " " << arr[i].second << endl;
	}
	cout << endl;*/
	// 12 12

	vector<pair<int, int>> result;
	for (int i = 0; i < N; i++)
	{
		bool flag = false;
		for (int j = 0; j < result.size(); j++)
		{
			if (arr[i].first == result[j].first && arr[i].second == result[j].second && arr[i].first != arr[i].second)
			{
				flag = true;
				break;
			}
			/*if (arr[i].first == arr[i].second)
			{
				if (result[j].first == result[j].second)
				{
					if (arr[i].first == result[j].first)
					{
						flag = true;
						break;
					}
				}
			}*/
			if (result[j].first < arr[i].first && result[j].second > arr[i].first)
			{
				flag = true;
				break;
			}
			if (result[j].first < arr[i].second && result[j].second > arr[i].second)
			{
				flag = true;
				break;
			}
			if (result[j].first > arr[i].first && result[j].first < arr[i].second)
			{
				flag = true;
				break;
			}
			if (result[j].second > arr[i].first && result[j].second < arr[i].second)
			{
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			continue;
		}
		else
		{
			// cout << arr[i].first << " " << arr[i].second << endl;
			result.push_back(arr[i]);
		}
	}

	cout << result.size() << endl;

	return 0;
}