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
    // -�� �������� ������ �ּ�, ������ �ִ�� �����.
    // �׷��� ���� ����, ���׵� ��ó�� -�� �������� �ٽ� ������. 
    // �Ŀ� -�� ���ų� ���� �ϳ��� ���� ������ �ݺ��Ѵ�. 

    string formula;
    cin >> formula;

    vector<string> numbers;
    string temp;
    for (int i = 0; i < formula.size(); i++)
    {
        if (formula[i] == '-')
        {
            numbers.push_back(temp);
            numbers.push_back("-");
            temp.clear();
        }
        else if (formula[i] == '+')
        {
            numbers.push_back(temp);
            numbers.push_back("+");
            temp.clear();
        }
        else
        {
            temp.push_back(formula[i]);
        }
    }
    numbers.push_back(temp);

    int result = 0;
    int temp_ = 0;
    bool flag = false;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] != "+" && numbers[i] != "-")
        {
            if (!flag)
            {
                result += stoi(numbers[i]);
            }
            else if (flag)
            {
                temp_ += stoi(numbers[i]);
            }
        }
        else if (numbers[i] == "-" && !flag)
        {
            flag = true;
        }
        else if (numbers[i] == "-" && flag)
        {
            result -= temp_;
            temp_ = 0;
        }
        else if (numbers[i] == "+")
        {
            continue;
        }
    }
    result -= temp_;

    cout << result << endl;

    return 0;
}