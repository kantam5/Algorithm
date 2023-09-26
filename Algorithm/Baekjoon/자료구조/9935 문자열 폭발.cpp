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

using namespace std;

int main()
{
    string s;
    string bomb;

    cin >> s >> bomb;

    string answer;

    int bomb_len = bomb.length();

    for (int i = 0; i < s.length(); ++i)
    {
        answer.push_back(s[i]);

        // 현재까지 채워넣은 answer의 길이가 폭탄 길이보다 클 경우만 비교
        if (answer.length() >= bomb_len)
        {
            // answer의 끝 부분이 폭탄과 같다면 폭발
            bool flag = true;
            for (int j = 0; j < bomb.length(); ++j)
            {
                if (answer[answer.length() - bomb_len + j] != bomb[j])
                {
                    flag = false;
                }
            }

            // 폭탄 부분 삭제
            if (flag)
            {
                answer.erase(answer.end() - bomb_len, answer.end());
            }
        }
    }

    if (answer.empty())
    {
        cout << "FRULA";
    }
    else
    {
        cout << answer;
    }

    return 0;
}