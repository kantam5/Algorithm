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

int ground[9][9];
bool num_vertical[10][9];                   // 행 숫자 입력된 것
bool num_horizontal[10][9];                 // 열 숫자 입력된 것
bool num_block[10][3][3];                   // 블럭 숫자 입력된 것

void Print()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << ground[i][j];
        }
        cout << endl;
    }
}

// current를 1씩 증가시켜서 보드를 1칸씩 옮겨서 검사한다. 
void solution(int current)
{
    if (current == 81)
    {
        Print();
        exit(0);                            // 프로그램 바로 종료
    }

    int current_x = (current) / 9;          // 현재 검사하는 보드의 행
    int current_y = (current) % 9;          // 현재 검사하는 보드의 열

    // 현재 검사하는 칸이 0이라면
    if (ground[current_x][current_y] == 0)
    {
        for (int k = 1; k <= 9; ++k)
        {
            // 현재 칸에 k가 입력될 수 있는지 검사
            if (!num_vertical[k][current_x] && !num_horizontal[k][current_y] && !num_block[k][current_x / 3][current_y / 3])
            {
                // 현재 칸에 k를 입력하고 현재칸의 다음 칸 검사
                ground[current_x][current_y] = k;
                num_vertical[k][current_x] = true;
                num_horizontal[k][current_y] = true;
                num_block[k][current_x / 3][current_y / 3] = true;

                solution(current + 1);

                // 현재칸의 다음 칸 검사 완료 후 백트래킹
                ground[current_x][current_y] = 0;
                num_vertical[k][current_x] = false;
                num_horizontal[k][current_y] = false;
                num_block[k][current_x / 3][current_y / 3] = false;
            }
        }
    }
    else
    {
        // 현재 칸이 0이 아니라면 다음 칸 검사
        solution(current + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    for (int i = 0; i < 9; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 9; ++j)
        {
            ground[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            num_vertical[ground[i][j]][i] = true;
            num_horizontal[ground[i][j]][j] = true;
            num_block[ground[i][j]][i / 3][j / 3] = true;
        }
    }

    // 0번째 칸 부터 검사
    solution(0);

    return 0;
}