#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int arr[10];
    vector<int> div_vector;

    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
        div_vector.push_back(arr[i] % 42);
    }

    sort(div_vector.begin(), div_vector.end());
    div_vector.erase(unique(div_vector.begin(), div_vector.end()), div_vector.end());

    cout << div_vector.size();

    return 0;
}