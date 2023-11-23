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

int nums[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    // ���� �Ѱ� �̻� �����ؾ� �ϹǷ� ù ��ҷ� �ʱ�ȭ�Ѵ�.
    int answer = nums[0];
    int current = nums[0];

    for (int i = 1; i < N; ++i)
    {
        // ���� �迭 ���ο� �ִ� ���� ������ current�̴�. 

        // current�� nums[i]���� �۴ٸ� ������ �迭�� ������ 
        // nums[i]�� ù ��ҷ� �ϴ� ���ο� �迭�� �����Ѵ�.
        current += nums[i];
        current = current < nums[i] ? nums[i] : current;

        // current�� �ִ밪�� ���̴�.
        answer = max(answer, current);
    }

    cout << answer;

    return 0;
}