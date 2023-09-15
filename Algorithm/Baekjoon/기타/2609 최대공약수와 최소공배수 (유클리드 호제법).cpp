#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int num1;
    int num2;
    cin >> num1 >> num2;

    int num_1 = max(num1, num2);
    int num_2 = min(num1, num2);

    int temp = num_1 % num_2;
    while (temp != 0)
    {
        num_1 = num_2;
        num_2 = temp;
        temp = num_1 % num_2;
    }

    // 최대공약수
    cout << num_2 << endl;

    // 최대공배수 
    cout << (num1 * num2) / num_2 << endl;

    return 0;
}