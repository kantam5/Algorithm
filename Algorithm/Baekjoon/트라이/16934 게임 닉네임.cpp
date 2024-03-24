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

	// Ư�� ���ڿ��� ������ �Էµ� ���ڿ��̶�� true ��ȯ
	bool Find(const char* str)
	{
		// ���ڿ��� ������ �����ߴٸ� ������ ���� ���ڿ����� ��ȯ
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

	// ���ڿ��� ������ �Էµ� ���ڿ����� ���λ��� �ش� ��带 ��ȯ
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

		// name�� ù ���ڿ��� ������ ���ڱ��� ������ ���λ縦 Ž��
		for (int j = 1; j < name.length() + 1; ++j)
		{
			char name_prefix[11];
			strcpy(name_prefix, name.substr(0, j).c_str());

			// ���� trie�� ���ڿ��� �߿��� name_prefix�� ���λ�� �ϴ� ���ڿ��� ���ٸ� name_prefix�� ���
			if (trie.HasPrefix(name_prefix) == NULL)
			{
				cout << name_prefix << '\n';
				flag = false;
				break;
			}
		}

		// name�� trie�� �Է�
		char name_char[11];
		strcpy(name_char, name.c_str());
		trie.Insert(name_char);

		// name�� �Էµ� Ƚ�� ����
		name_map[name]++;

		// name�� ���λ縦 �г������� �� �� ���� ���
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