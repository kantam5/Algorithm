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
		// 마지막 문자라면 isEnd를 true로 설정
		if (*str == NULL)
		{
			isEnd = true;
			return;
		}

		// 문자열의 첫 문자에 해당하는 자식 노드를 탐색
		int current = *str - 'a';
		if (child[current] == NULL)
		{
			child[current] = new Trie();
		}

		// 다음 문자를 인자로 자식 노드의 Insert 실행
		child[current]->Insert(str + 1);
	}

	bool Find(const char* str)
	{
		if (*str == NULL)
		{
			return false;
		}

		// 현재까지의 문자열이 들어온 적 있는 문자열인 경우
		if (isEnd == true)
		{
			return true;
		}

		int current = *str - 'a';
		if (child[current] == NULL)
		{
			return false;
		}

		return child[current]->Find(str + 1);
	}

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

	// Trie의 노드는 입력되는 문자의 종류만큼의 자식 노드를 가진다.
	Trie* child[MAX_NUM];
	bool isEnd;

};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	Trie trie;

	for (int i = 0; i < N; ++i)
	{
		char s[501];
		cin >> s;

		trie.Insert(s);
	}

	int answer = 0;
	for (int i = 0; i < M; ++i)
	{
		char s[501];
		cin >> s;

		if (trie.HasPrefix(s) != NULL)
		{
			answer++;
		}
	}

	cout << answer;

	return 0;
}