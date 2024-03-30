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

struct Trie
{
	map<string, Trie*> child;

	~Trie()
	{
		for (pair<string, Trie*> c : child)
		{
			delete c.second;
		}
	}

	void InsertWord(vector<string>& wordList, int idx)
	{
		if (wordList.size() == idx)
		{
			return;
		}

		// ���� Trie�� child �߿��� wordList[idx]�� ���ٸ� Trie�� ���� ���� child�� �ִ´�.
		if (child.find(wordList[idx]) == child.end())
		{
			Trie* trie = new Trie();

			child.insert(make_pair(wordList[idx], trie));
		}

		// wordList[idx]�� ���� child�� ���� wordList[idx + 1]�� �ִ´�.
		child[wordList[idx]]->InsertWord(wordList, idx + 1);
	}

	void Print(int depth)
	{
		for (pair<string, Trie*> c : child)
		{
			for (int i = 0; i < depth; ++i)
			{
				cout << "--";
			}
			cout << c.first << '\n';

			c.second->Print(depth + 1);
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Trie trie;

	while (N--)
	{
		int K;
		cin >> K;

		vector<string> wordList;
		string word;

		while (K--)
		{
			cin >> word;
			wordList.push_back(word);
		}

		trie.InsertWord(wordList, 0);
	}

	trie.Print(0);

	return 0;
}