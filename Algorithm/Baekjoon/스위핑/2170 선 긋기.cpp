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

vector<pair<int, int>> lines;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int start, end;
        cin >> start >> end;

        lines.push_back(make_pair(start, end));
    }

    // ������ �����Ѵ�.
    sort(lines.begin(), lines.end());

    int answer = 0;
    int start = lines[0].first;
    int end = lines[0].second;
    for (int i = 1; i < lines.size(); ++i)
    {
        // �˻��ϴ� ���� ������ ���� �ߴ� ���� ������ �۰ų� ���� ���̶�� �ѹ��� ���� �� �ִ�.
        if (lines[i].first <= end)
        {
            // �˻��ϴ� ���� ���� ���� �ߴ� ���� ������ ũ�ٸ� �˻��ϴ� ���� ������ �ߴ´�.
            if (end < lines[i].second)
            {
                end = lines[i].second;
            }
        }
        // �˻��ϴ� ���� ������ ���� �ߴ� ���� ������ ũ�ٸ� ���� ���� �׾�� �Ѵ�.
        else
        {
            // ���� �߰� �ִ� ���� ���̸� answer�� �߰��ϰ�
            // ���ο� ���� �ߴ´�.
            answer += (end - start);
            start = lines[i].first;
            end = lines[i].second;
        }
    }
    // ������ ���� ���� �ݺ������� ���� �����Ƿ� ���� �߰��Ѵ�.
    answer += (end - start);

    cout << answer;

    return 0;
}