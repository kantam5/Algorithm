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
        // �빮��
        auto it1 = find(_vector1.begin(), _vector1.end(), (int)_string[i]);
        // �ҹ���
        auto it2 = find(_vector1.begin(), _vector1.end(), (int)_string[i] - 32);

        // �빮�� �ҹ��� ����
        if (it1 == _vector1.end() && it2 == _vector1.end())
        {
            // �ҹ����� ����̹Ƿ� �빮�ڷ� ��ȯ�ؼ� push
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
            // �ҹ��ڵ� üũ
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