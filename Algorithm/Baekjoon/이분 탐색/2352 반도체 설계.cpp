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

vector<int> nums;

// ������ �Էµ� nums���� num ������ ���߿���
// �ִ��� num���� ��ü�Ѵ�.
void binary_input(int num)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int current = nums[mid];

        if (current < num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    // �̺� Ž�� �� start�� ������ ��ġ�� �����ȴ�.
    nums[start] = num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // ù��° ���� �ٷ� ����
    int temp;
    cin >> temp;
    nums.push_back(temp);

    // �Է��� �����鼭 �˻�
    int index = 0;
    for (int i = 1; i < n; ++i)
    {
        int temp_;
        cin >> temp_;

        // �Է� ���� ���� ���� nums�� ������ ������ ũ�ٸ� �ٷ� ����
        if (nums[index] < temp_)
        {
            nums.push_back(temp_);
            index++;
        }
        // ���϶�� �Է¹��� ������ �ٷ� �Ʒ��� ���� ���� �̺� Ž���Ͽ� ��ü
        else
        {
            binary_input(temp_);
        }
    }

    // nums�� ���� �� �����ϴ� �κ� ������ ����.
    cout << nums.size();

    return 0;
}