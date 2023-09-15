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

int cache[101][100001];
int W[101];
int V[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int K;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (i == 0 || j == 0)
                cache[i][j] = 0;
            else
            {
                // ���� üũ�ϴ� ������ �� �� �ִ� ���Զ��
                if (j - W[i] >= 0)
                    // ������ üũ�� ������ ĳ�ÿ� ���� üũ�ϴ� ������ �� �� �ֵ��� ���Ը� Ȯ���ϰ� ������ �߰����� ���� ��ġ�� ��
                    cache[i][j] = max(cache[i - 1][j], V[i] + cache[i - 1][j - W[i]]);
                // ���� �� �� ���� ���Զ�� ������ ĳ�ø� �ִ´�.
                else
                    cache[i][j] = cache[i - 1][j];
            }
        }
    }

    cout << cache[N][K];

    return 0;
}