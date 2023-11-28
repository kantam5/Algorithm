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

using namespace std;

int nums[30000];
int menu[3001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    // �ʱⰪ ����
    // 0������ k - 1�� ���� �ʹ��� ������ current�� ����
    int current = 0;
    for (int i = 0; i < k; ++i)
    {
        if (menu[nums[i]] == 0)
        {
            current++;
        }
        menu[nums[i]]++;
    }

    // c�ʹ��� ���õ��� �ʾҴٸ� ���� �ʹ��� ������ 1�� �߰��ȴ�.
    int answer = menu[c] == 0 ? current + 1 : current;

    // �����̵� ������ ������� ������ ���� k�� �����̴�.
    // start + 1���� end������ �ʹ��� ������ current�̴�. 
    // start�� 1������ų ��, ���翡�� ������ �߰��Ǵ� �ʹ��� ������ ����ϸ� �ȴ�. 
    for (int start = 0; start < N; ++start)
    {
        int end = (start + k) % N;

        // ���� ������ �ʹ� �߿��� start�ʹ��� �ϳ� ������.
        // start�ʹ��� ���� ��, ������ �ʹ� �� start�ʹ��� �ϳ��� ���ٸ�
        // �ʹ��� ������ �ϳ� �����Ͱ� ����.
        menu[nums[start]]--;
        if (menu[nums[start]] == 0)
        {
            current--;
        }

        // ���� ������ �ʹ� �߿��� end�ʹ��� �ϳ� �߰��ȴ�.
        // ���� ������ �ʹ� �߿��� end�ʹ��� ���ٸ� 
        // �ʹ��� ������ �ϳ� �þ�Ͱ� ����.
        if (menu[nums[end]] == 0)
        {
            current++;
        }
        menu[nums[end]]++;

        // c�ʹ��� ���õ� �ʹ信 ���ٸ� ������ �ϳ� �þ �Ͱ� ����. 
        // �̹� ���õǾ��ٸ� ������ ������ ����.
        if (menu[c] == 0)
        {
            answer = max(answer, current + 1);
        }
        else
        {
            answer = max(answer, current);
        }
    }

    cout << answer;

    return 0;
}
