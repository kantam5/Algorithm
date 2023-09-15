#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b)
{
    // ���ڿ��� ���� �� ����
    // ���ڿ��� ���̰� ���ٸ� ���ĺ� ������ ����
    // string������ �� �����ڴ� ���ĺ��� ������.
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

    // ���� ���� ����, ���ĺ� ���� ����
    sort(strings.begin(), strings.end(), compare);

    // �ߺ��ȴٸ� ����� �ʿ� ����. 
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