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

const int MAX_NUM = 10;

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
		// ������ ���ڶ�� isEnd�� true�� ����
		if (*str == NULL)
		{
			isEnd = true;
			return;
		}

		// ���ڿ��� ù ���ڿ� �ش��ϴ� �ڽ� ��带 Ž��
		int current = *str - '0';
		if (child[current] == NULL)
		{
			child[current] = new Trie();
		}

		// ���� ���ڸ� ���ڷ� �ڽ� ����� Insert ����
		child[current]->Insert(str + 1);
	}

	bool Find(const char* str)
	{
		if (*str == NULL)
		{
			return false;
		}

		// ��������� ���ڿ��� ���� �� �ִ� ���ڿ��� ���
		if (isEnd == true)
		{
			return true;
		}

		int current = *str - '0';
		if (child[current] == NULL)
		{
			return false;
		}

		return child[current]->Find(str + 1);
	}

	// Trie�� ���� �ԷµǴ� ������ ������ŭ�� �ڽ� ��带 ������.
	Trie* child[MAX_NUM];
	bool isEnd;

};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Trie* trie = new Trie();
		vector<string> nums;

		for (int i = 0; i < n; ++i)
		{
			char num[11];
			cin >> num;

			trie->Insert(num);
			nums.push_back(num);
		}

		bool flag = false;
		for (int i = 0; i < n; ++i)
		{
			char num[11];
			strcpy(num, nums[i].c_str());

			if (trie->Find(num) != NULL)
			{
				flag = true;
				break;
			}
		}

		if (flag == true)
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
		}
	}

	return 0;
}
