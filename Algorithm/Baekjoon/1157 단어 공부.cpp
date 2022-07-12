#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string _string = "";
    cin >> _string;

    vector<int> _vector1;
    vector<int> _vector2(36, 0);

    int max = 0;
    int count = 0;
    char result = '?';

    for (int i = 0; i < _string.size(); i++)
    {
        // 대문자
        auto it1 = find(_vector1.begin(), _vector1.end(), (int)_string[i]);
        // 소문자
        auto it2 = find(_vector1.begin(), _vector1.end(), (int)_string[i] - 32);

        // 대문자 소문자 구분
        if (it1 == _vector1.end() && it2 == _vector1.end())
        {
            // 소문자인 경우이므로 대문자로 변환해서 push
            if ((int)_string[i] > 90)
            {
                _vector1.push_back((int)_string[i] - 32);
                it2 = find(_vector1.begin(), _vector1.end(), (int)_string[i] - 32);
                int index = distance(_vector1.begin(), it2);
                _vector2[index] = _vector2[index] + 1;
            }
            else
            {
                _vector1.push_back((int)_string[i]);
                it1 = find(_vector1.begin(), _vector1.end(), (int)_string[i]);
                int index = distance(_vector1.begin(), it1);
                _vector2[index] = _vector2[index] + 1;
            }
        }
        else
        {
            // 소문자도 체크
            if ((int)_string[i] > 90)
            {
                int index = distance(_vector1.begin(), it2);
                _vector2[index] = _vector2[index] + 1;
            }
            else
            {
                int index = distance(_vector1.begin(), it1);
                _vector2[index] = _vector2[index] + 1;
            }
        }
    }

    for (int i = 0; i < _vector2.size(); i++)
    {
        if (max < _vector2[i])
        {
            max = _vector2[i];
            result = (char)_vector1[i];
        }
    }

    for (int i = 0; i < _vector2.size(); i++)
    {
        if (max == _vector2[i])
        {
            count++;
        }
    }

    if (count > 1)
    {
        result = '?';
    }

    cout << result << endl;

    return 0;
}