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

	int S = 0;

	while (M--)
	{
		string command;
		cin >> command;

		if (command == "add")
		{
			int temp;
			cin >> temp;
			// 비트 or 연산자
			S |= (1 << temp);
		}
		else if (command == "remove")
		{
			int temp;
			cin >> temp;
			// 비트 and 연산자
			S &= ~(1 << temp);
		}
		else if (command == "check")
		{
			int temp;
			cin >> temp;
			// 비트 and 연산자로 해당자리가 1인지 확인
			if (S & (1 << temp))
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (command == "toggle")
		{
			int temp;
			cin >> temp;
			// 비트 xor 연산자
			S ^= (1 << temp);
		}
		else if (command == "all")
		{
			// 1000000000000000000000 - 1 = 11111111111111111111
			S = (1 << 21) - 1;
		}
		else if (command == "empty")
		{
			// 00000000000000000000
			S = 0;
		}
	}

	return 0;
}