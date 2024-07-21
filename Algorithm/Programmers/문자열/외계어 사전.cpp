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
#include <unordered_set>

using namespace std;

int solution(vector<string> spell, vector<string> dic)
{
	int answer = 2;

	for (const auto& s : dic)
	{
		bool flag = true;

		for (const auto& c : spell)
		{
			if (s.find(c) == string::npos)
			{
				flag = false;
				break;
			}
		}

		if (true == flag)
		{
			answer = 1;
			break;
		}
	}

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> spell;
	vector<string> dic;

	spell = { "s", "o", "m", "d" };
	dic = { "moos", "dzx", "smm", "sunmmo", "som" };

	cout << solution(spell, dic);

	return 0;
}