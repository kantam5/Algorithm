#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class comp
{
public:
    bool operator()(const int& lhs, const int& rhs)
    {
        if (abs(lhs) == abs(rhs))
        {
            return lhs > rhs;
        }
        return abs(lhs) > abs(rhs);
    }
};

int main()
{
    int repeat;
    scanf_s("%d", &repeat);

    priority_queue<int, vector<int>, comp> pq;

    int temp;
    for (int i = 0; i < repeat; i++)
    {
        scanf_s("%d", &temp);
        if (temp == 0)
        {
            if (pq.empty())
            {
                printf("0\n");
            }
            else
            {
                int num = pq.top();
                pq.pop();
                printf("%d\n", num);
            }
        }
        else
        {
            pq.push(temp);
        }
    }

    return 0;
}