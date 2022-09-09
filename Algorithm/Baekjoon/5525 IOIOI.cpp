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

using namespace std;

int N;
bool solution(string S, int i)
{
    string IOI;
    IOI.push_back('I');
    for (int j = 0; j < N; j++)
    {
        IOI.push_back('O');
        IOI.push_back('I');
    }

    string temp = S.substr(i, 1 + 2 * N);
    if (temp == IOI)
    {
        return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    string S;

    cin >> N >> M >> S;

    int result = 0;
    for (int i = 0; i < M; i++)
    {
        int count = 0;

        if (S[i] == 'O')
        {
            continue;
        }
        else
        {
            while (S[i + 1] == 'O' && S[i + 2] == 'I')
            {
                count++;
                if (count == N)
                {
                    count--;
                    result++;
                }
                i += 2;
            }
            count = 0;
        }
    }

    cout << result << '\n';

    return 0;
}