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

// �� �����ͷ� �� ������ �����ϸ� �Ӹ������ üũ�Ѵ�. 
int solution(string current, int start, int end, int in_diff_count)
{
    int diff_count = in_diff_count;
    while (start <= end)
    {
        if (current[start] == current[end])
        {
            start++;
            end--;
            continue;
        }

        // current[start]�� current[end]�� ���� ���� �ʴٸ�
        if (current[start] != current[end])
        {
            // diff_count�� 1 ������Ų��. 
            diff_count++;
            // �̹� diff_count�� 1�� ���¿��� �Լ��� ����Ǿ��ٸ�
            // ��͸� ���� �ʰ� ��� diff_count�� ��ȯ�Ѵ�.
            if (diff_count > 1)
            {
                break;
            }

            // start�� end �� �� �ϳ��� ������ ���¿��� �ٽ� �� �����͸� �ǽ��ϵ��� ����Ѵ�.
            diff_count = min(solution(current, start + 1, end, diff_count),
                solution(current, start, end - 1, diff_count));

            break;
        }
    }

    return diff_count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        string current;
        cin >> current;

        int start = 0;
        int end = current.length() - 1;

        int diff_count = solution(current, start, end, 0);

        cout << diff_count << '\n';
    }

    return 0;
}