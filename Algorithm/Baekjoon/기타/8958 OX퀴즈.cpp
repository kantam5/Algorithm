#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int repeat;
    std::cin >> repeat;

    int* result_array = new int[repeat];

    string answer;
    int score = 0;
    int result = 0;

    for (int i = 0; i < repeat; i++)
    {
        cin >> answer;
        for (int i = 0; i < answer.length(); i++)
        {
            if (answer[i] == 'O')
            {
                score++;
                result += score;
            }
            if (answer[i] == 'X')
            {
                score = 0;
            }
        }
        result_array[i] = result;
        score = 0;
        result = 0;
    }

    for (int i = 0; i < repeat; i++)
    {
        cout << result_array[i] << endl;
    }

    return 0;
}