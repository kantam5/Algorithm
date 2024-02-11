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
#include <climits>
#include <sstream>
#include <cstdlib>

using namespace std;

vector<int> hole;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        hole.push_back(temp);
    }

    // ���� �ʼ�
    sort(hole.begin(), hole.end());

    // ���� ���� i���� �������� �ٿ��� ��, ���� �� �ִ� ������ �Ÿ��� hole[i] + L - 1 �����̴�.
    // �� �Ÿ����� �� ������ ���� �� �����Ƿ�, ���ο� �������� ����ؾ� �Ѵ�. 
    int answer = 0;
    int start = hole[0];
    for (int i = 0; i < N; ++i)
    {
        if (hole[i] > start + L - 1)
        {
            // start�� �����Ѵ�.
            start = hole[i];
            answer++;
        }
    }

    // ������ start���� ����ϴ� ������
    cout << answer + 1;

    return 0;
}
