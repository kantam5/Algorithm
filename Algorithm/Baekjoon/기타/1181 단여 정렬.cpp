#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b)
{
    // 문자열의 길이 순 정렬
    // 문자열의 길이가 같다면 알파벳 순서로 정렬
    // string사이의 비교 연산자는 알파벳에 따른다.
    return a.size() == b.size() ?
        a < b : a.size() < b.size();
}

int main()
{
    int repeat;
    cin >> repeat;

    vector<string> strings;
    string _string;
    string temp;

    for (int i = 0; i < repeat; i++)
    {
        cin >> _string;
        strings.push_back(_string);
    }

    // 길이 순서 정렬, 알파벳 순서 정렬
    sort(strings.begin(), strings.end(), compare);

    // 중복된다면 출력할 필요 없다. 
    for (string s : strings)
    {
        if (temp == s)
        {
            continue;
        }
        cout << s << endl;
        temp = s;
    }

    return 0;
}