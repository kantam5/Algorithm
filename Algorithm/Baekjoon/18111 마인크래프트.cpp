#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool equal_arr(int** arr, int row, int col)
{
    int temp = arr[0][0];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (temp != arr[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    // 그냥 인벤토리에 있는 걸로 다 채울 수 있는지부터 체크
    // 같은 높이로 쌓을 수 없다면 제일 높은 층, 한 층 씩 빼서 그 높이만큼 다 채울 수 있는지 체크

    // 아니면 0에서 최대 높이까지의 모든 경우에서 걸리는 시간과 높이를 비교

    int height;
    int width;
    int inventory;

    vector<pair<int, int>> answers;
    pair<int, int> answer;


    cin >> height >> width >> inventory;

    int** arr = new int* [height];
    for (int i = 0; i < height; i++)
    {
        arr[i] = new int[width];
    }

    // 집터 입력
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> arr[i][j];
        }
    }

    int maxi;


    cout << maxi << endl;

    // 맞는 경우
    /*if (equal_arr(arr, height, width))
    {
        answers.push_back(answer);
    }*/


    return 0;
}