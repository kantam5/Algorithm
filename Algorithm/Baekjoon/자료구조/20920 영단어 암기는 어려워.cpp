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

unordered_map<string, int> word_count;

bool compare(pair<string, int> a, pair<string, int> b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    else if (a.first.length() != b.first.length())
    {
        return a.first.length() > b.first.length();
    }
    else
    {
        return a.first < b.first;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        string word;
        cin >> word;

        if (word.length() >= M)
        {
            word_count[word]++;
        }
    }

    // map의 iterator는 pair로 이루어진다. 
    // 동일한 pair로 구성된 vector를 다음의 생성자로 만들 수 있다.
    vector<pair<string, int>> words(word_count.begin(), word_count.end());

    sort(words.begin(), words.end(), compare);

    for (pair<string, int>& word : words)
    {
        cout << word.first << '\n';
    }

    return 0;
}
