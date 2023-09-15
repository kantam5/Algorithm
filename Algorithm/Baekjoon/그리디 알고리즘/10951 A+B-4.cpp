#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int num1 = 0;
    int num2 = 0;
    while (scanf_s("%d %d", &num1, &num2) != EOF)
    {
        cout << num1 + num2 << endl;
    }

    return 0;
}