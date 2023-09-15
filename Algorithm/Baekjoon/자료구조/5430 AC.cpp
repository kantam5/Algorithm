#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <memory.h>
#include <unordered_map>
#include <cmath>
#include <deque>

using namespace std;

bool visited[10000];
typedef struct
{
    int n;
    string distance;
} types;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        string p;
        cin >> p;

        int D_count = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'D')
            {
                D_count++;
            }
        }

        int n;
        string arr;
        cin >> n >> arr;

        // R�� ���� flag�� �޸��Ͽ� �հ� �ڸ� �Ǻ��Ѵ�. 
        deque<int> dq;
        int digit_count = 0;
        string temp;
        for (int i = 0; i < arr.size(); i++)
        {
            if (isdigit(arr[i]))
            {
                temp.push_back(arr[i]);
                digit_count++;
            }
            else if (arr[i] == ',' || arr[i] == ']' && !temp.empty())
            {
                dq.push_back(stoi(temp));
                digit_count++;
                temp.clear();
            }
        }

        // d�� ���� n�� ���Ͽ� error�� �̸� �Ǻ�
        if (D_count > n)
        {
            cout << "error" << '\n';
            continue;
        }

        bool flag = true;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'R')
            {
                flag = !flag;
            }
            else if (p[i] == 'D')
            {
                if (flag == true)
                {
                    dq.pop_front();
                }
                else if (flag == false)
                {
                    dq.pop_back();
                }
            }
        }

        int dq_size = dq.size();
        if (flag == true)
        {
            cout << "[";
            for (int i = 0; i < dq_size - 1; i++)
            {
                cout << dq.front() << ",";
                dq.pop_front();
            }
            if (!dq.empty())
            {
                cout << dq.front();
            }
            cout << "]" << '\n';
        }
        else if (flag == false)
        {
            cout << "[";
            for (int i = 0; i < dq_size - 1; i++)
            {
                cout << dq.back() << ",";
                dq.pop_back();
            }
            if (!dq.empty())
            {
                cout << dq.front();
            }
            cout << "]" << '\n';
        }
    }

    return 0;
}