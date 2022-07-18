#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char chess_board_1[8][8] =
{
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
};

char chess_board_2[8][8] =
{
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
};

// arr[a][b]에서 시작하는 8, 8짜리 체스판 2차원 배열을 반환
int slice_arr(char** arr, int a, int b)
{
    int diff_1 = 0;
    int diff_2 = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arr[a + i][b + j] != chess_board_1[i][j])
            {
                diff_1++;
            }
            if (arr[a + i][b + j] != chess_board_2[i][j])
            {
                diff_2++;
            }
        }
    }

    return min(diff_1, diff_2);
}

int main()
{
    // 자른것중에 체스판 행렬과 다른 판의 수를 센다. 
    int row;
    int col;
    cin >> row >> col;

    vector<int> diff;

    char** arr = new char* [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new char[col];
    }

    // 체스판 입력
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i <= row - 8; i++)
    {
        for (int j = 0; j <= col - 8; j++)
        {
            diff.push_back(slice_arr(arr, i, j));
        }
    }

    sort(diff.begin(), diff.end());

    cout << diff[0];

    return 0;
}