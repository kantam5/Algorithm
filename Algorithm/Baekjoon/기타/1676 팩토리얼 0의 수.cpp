#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#include <regex>

using namespace std;


int main()
{
    // 5ÀÇ ¼ö
    int N;
    cin >> N;

    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        int count = 0;
        int temp = i;
        while (temp % 5 == 0 && temp != 0)
        {
            count++;
            temp /= 5;
        }

        result += count;
    }

    cout << result << endl;

    return 0;
}