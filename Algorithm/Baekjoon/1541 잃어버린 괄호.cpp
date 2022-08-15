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
    // -를 기준으로 우항을 최소, 좌항을 최대로 만든다.
    // 그렇게 만든 우항, 좌항도 위처럼 -를 기준으로 다시 나눈다. 
    // 식에 -가 없거나 항이 하나만 남을 때까지 반복한다. 

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