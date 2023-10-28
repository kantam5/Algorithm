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

using namespace std;

vector<int> shoots;
vector<pair<int, int>> animals;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int M, N, L;
    cin >> M >> N >> L;

    for (int i = 0; i < M; ++i)
    {
        int temp;
        cin >> temp;
        shoots.push_back(temp);
    }

    for (int i = 0; i < N; ++i)
    {
        int x;
        int y;
        cin >> x >> y;
        animals.push_back(make_pair(x, y));
    }

    // ��븦 ����
    sort(shoots.begin(), shoots.end());

    // �� �������� ��� ��ġ�� ��뿡�� ����� �������� �̺� Ž��
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        int start = 0;
        int end = M - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            // mid ��뿡�� ��� �������� �˻�
            int dist = abs(animals[i].first - shoots[mid]) + animals[i].second;
            if (dist <= L)
            {
                answer++;
                break;
            }

            // ������ mid ����� ���ʿ� �ִٸ� end�� ����
            // �����ʿ� �ִٸ� start�� ����
            if (animals[i].first < shoots[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }

    cout << answer;

    return 0;
}