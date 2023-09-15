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
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	int M;
	cin >> N >> M;
	// scanf_s("%d %d", &N, &M);

	int pokemon_count = 1;
	unordered_map<string, int> encyclopedia_1;
	unordered_map<int, string> encyclopedia_2;
	for (int i = 0; i < N; i++)
	{
		string temp_string;
		cin >> temp_string;

		encyclopedia_1.insert(make_pair(temp_string, pokemon_count));
		encyclopedia_2.insert(make_pair(pokemon_count, temp_string));

		pokemon_count++;
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;

		if (atoi(temp.c_str()) == 0)
		{
			cout << encyclopedia_1[temp] << "\n";
			// printf("%d\n", encyclopedia_1[temp]);
		}
		else
		{
			cout << encyclopedia_2[atoi(temp.c_str())] << "\n";
			// printf("%s\n", encyclopedia_2[atoi(temp.c_str())].c_str());
		}
	}

	return 0;

}