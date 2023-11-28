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

    // 초기값 설정
    // 0번부터 k - 1번 까지 초밥의 종류를 current에 저장
    int current = 0;
    for (int i = 0; i < k; ++i)
    {
        if (menu[nums[i]] == 0)
        {
            current++;
        }
        menu[nums[i]]++;
    }

    // c초밥이 선택되지 않았다면 현재 초밥의 종류에 1이 추가된다.
    int answer = menu[c] == 0 ? current + 1 : current;

    // 슬라이딩 윈도우 방식으로 구간의 길이 k로 고정이다.
    // start + 1에서 end까지의 초밥의 종류가 current이다. 
    // start를 1증가시킬 때, 현재에서 빠지고 추가되는 초밥의 종류만 계산하면 된다. 
    for (int start = 0; start < N; ++start)
    {
        int end = (start + k) % N;

        // 현재 선택한 초밥 중에서 start초밥은 하나 빠진다.
        // start초밥을 뺐을 때, 선택한 초밥 중 start초밥이 하나도 없다면
        // 초밥의 종류가 하나 빠진것과 같다.
        menu[nums[start]]--;
        if (menu[nums[start]] == 0)
        {
            current--;
        }

        // 현재 선택한 초밥 중에서 end초밥은 하나 추가된다.
        // 현재 선택한 초밥 중에서 end초밥이 없다면 
        // 초밥의 종류가 하나 늘어난것과 같다.
        if (menu[nums[end]] == 0)
        {
            current++;
        }
        menu[nums[end]]++;

        // c초밥이 선택된 초밥에 없다면 종류가 하나 늘어난 것과 같다. 
        // 이미 선택되었다면 종류에 변함은 없다.
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
