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

const int MAX_NUM = 26;

struct Trie
{
	Trie()
		: isEnd(false)
	{
		for (int i = 0; i < MAX_NUM; ++i)
		{
			child[i] = NULL;
		}
	}

	~Trie()
	{
		for (int i = 0; i < MAX_NUM; ++i)
		{
			if (child[i] != NULL)
			{
				delete child[i];
			}
		}
	}

	void Insert(const char* str)
	{
		if (*str == NULL)
		{
			isEnd = true;
			return;
		}

		int current = *str - 'a';
		if (child[current] == NULL)
		{
			child[current] = new Trie();
		}

		child[current]->Insert(str + 1);
	}

	// 특정 문자열이 이전에 입력된 문자열이라면 true 반환
	bool Find(const char* str)
	{
		// 문자열의 끝까지 도달했다면 이전에 들어온 문자열인지 반환
		if (*str == NULL)
		{
			return isEnd;
		}

		int current = *str - 'a';
		if (child[current] == NULL)
		{
			return false;
		}

		return child[current]->Find(str + 1);
	}

	// 문자열이 이전에 입력된 문자열들의 접두사라면 해당 노드를 반환
	Trie* HasPrefix(const char* str)
	{
		if (*str == NULL)
		{
			return this;
		}

		int current = *str - 'a';
		if (child[current] == NULL)
		{
			return NULL;
		}

		return child[current]->HasPrefix(str + 1);
	}

	Trie* child[MAX_NUM];
	bool isEnd;

};

unordered_map<string, int> name_map;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Trie trie;

	for (int i = 0; i < N; ++i)
	{
		string name;
		cin >> name;

		bool flag = true;

		// name의 첫 문자에서 마지막 문자까지 가능한 접두사를 탐색
		for (int j = 1; j < name.length() + 1; ++j)
		{
			char name_prefix[11];
			strcpy(name_prefix, name.substr(0, j).c_str());

			// 현재 trie의 문자열들 중에서 name_prefix를 접두사로 하는 문자열이 없다면 name_prefix를 출력
			if (trie.HasPrefix(name_prefix) == NULL)
			{
				cout << name_prefix << '\n';
				flag = false;
				break;
			}
		}

		// name을 trie에 입력
		char name_char[11];
		strcpy(name_char, name.c_str());
		trie.Insert(name_char);

		// name이 입력된 횟수 증가
		name_map[name]++;

		// name의 접두사를 닉네임으로 쓸 수 없는 경우
		if (flag)
		{
			if (name_map[name] != 1)
			{
				cout << name << name_map[name] << '\n';
			}
			else
			{
				cout << name << '\n';
			}
		}
	}

	return 0;
}