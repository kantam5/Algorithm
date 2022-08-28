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


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;

	bool S[21];
	memset(S, false, sizeof(S));

	while (M--)
	{
		string command;
		cin >> command;

		if (command == "add")
		{
			int temp;
			cin >> temp;
			if (S[temp] == false)
			{
				S[temp] = true;
			}
		}
		else if (command == "remove")
		{
			int temp;
			cin >> temp;
			if (S[temp] == true)
			{
				S[temp] = false;
			}
		}
		else if (command == "check")
		{
			int temp;
			cin >> temp;
			cout << (int)S[temp] << '\n';
		}
		else if (command == "toggle")
		{
			int temp;
			cin >> temp;
			S[temp] = !S[temp];
		}
		else if (command == "all")
		{
			memset(S, true, sizeof(S));
		}
		else if (command == "empty")
		{
			memset(S, false, sizeof(S));
		}
	}

	return 0;
}