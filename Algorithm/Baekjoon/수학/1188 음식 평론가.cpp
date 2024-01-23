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

int gcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }

    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // �ҽ����� ���ڷ� �̾���� ����, ��а����� ������ ���� �ַ��� N / M ����ؾ� �Ѵ�.
    // �׷��Ƿ�, ��������� �ҽ����� (M - 1)�� �߷����Ѵ�.
    // �ҽ����� ���ڷ� �̾���� �����̹Ƿ�, �̹� �߷��ִ� �κ��� �ִ�.
    // �� �߷��ִ� �κ��� (M - 1)�� �ڸ� ��ġ�� ������ ���� �ش� �κ��� Ƚ������ �����ؾ� �Ѵ�. 
    // �� ������ �κ��� (N�� M�� �ִ����� - 1)�� �ִ�.
    // �׷��Ƿ�, ������ �Ʒ��� ����.
    cout << (M - 1) - (gcd(N, M) - 1);

    return 0;
}
