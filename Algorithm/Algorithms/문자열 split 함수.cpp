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

vector<string> split(string str, string Delimiter)
{
    vector<string> result;

    size_t beg, pos = 0;
    while ((beg = str.find_first_not_of(Delimiter, pos)) != string::npos)
    {
        pos = str.find_first_of(Delimiter, beg + 1);

        result.push_back(str.substr(beg, pos - beg));
    }

    return result;
}

int divide_minus(string formula)
{
    vector<int> minus_index;
    for (int i = 0; i < formula.size(); i++)
    {
        if (formula[i] == '-')
        {
            minus_index.push_back(i);
        }
    }


    // -가 없는 경우
    if (minus_index.size() == 0)
    {
        vector<string> formula_splited;
        formula_splited = split(formula, { "+" });

        int result = 0;
        for (int i = 0; i < formula_splited.size(); i++)
        {
            result += stoi(formula_splited[i]);
        }

        return result;
    }


    int mini = 2147483647;
    int min_minus_index = 1;
    for (int i = 0; i < minus_index.size(); i++)
    {
        string right_formula;
        vector<char> right_operators;
        vector<string> right_formula_splited;
        for (int j = 0; j < minus_index[i]; j++)
        {
            right_formula.push_back(formula[j]);
            if (formula[j] == '-' || formula[j] == '+')
            {
                right_operators.push_back(formula[j]);
            }
        }
        right_formula_splited = split(right_formula, { "+-" });

        int right_result = stoi(right_formula_splited[0]);
        for (int j = 0; j < right_operators.size(); j++)
        {
            if (right_operators[j] == '+')
            {
                right_result += stoi(right_formula_splited[j + 1]);
            }
            else if (right_operators[j] == '-')
            {
                right_result -= stoi(right_formula_splited[j + 1]);
            }
        }

        string left_formula;
        vector<char> left_operators;
        vector<string> left_formula_splited;
        for (int j = minus_index[i] + 1; j < formula.size(); j++)
        {
            left_formula.push_back(formula[j]);
            if (formula[j] == '-' || formula[j] == '+')
            {
                left_operators.push_back(formula[j]);
            }
        }
        left_formula_splited = split(left_formula, { "+-" });

        int left_result = stoi(left_formula_splited[0]);
        for (int j = 0; j < left_operators.size(); j++)
        {
            if (left_operators[j] == '+')
            {
                left_result += stoi(left_formula_splited[j + 1]);
            }
            else if (left_operators[j] == '-')
            {
                left_result -= stoi(left_formula_splited[j + 1]);
            }
        }

        if (right_result - left_result < mini)
        {
            mini = right_result - left_result;
            min_minus_index = minus_index[i];
        }
    }

    string right = formula.substr(0, min_minus_index);
    string left = formula.substr(min_minus_index + 1);

    return divide_minus(right) - divide_minus(left);
}

int main()
{
    // -를 기준으로 우항을 최소, 좌항을 최대로 만든다.
    // 그렇게 만든 우항, 좌항도 위처럼 -를 기준으로 다시 나눈다. 
    // 식에 -가 없거나 항이 하나만 남을 때까지 반복한다. 

    string formula;
    cin >> formula;

    cout << divide_minus(formula) << endl;

    return 0;
}