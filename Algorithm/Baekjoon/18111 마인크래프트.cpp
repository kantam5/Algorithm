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
    // �׳� �κ��丮�� �ִ� �ɷ� �� ä�� �� �ִ������� üũ
    // ���� ���̷� ���� �� ���ٸ� ���� ���� ��, �� �� �� ���� �� ���̸�ŭ �� ä�� �� �ִ��� üũ

    // �ƴϸ� 0���� �ִ� ���̱����� ��� ��쿡�� �ɸ��� �ð��� ���̸� ��

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

    // ���� �Է�
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> arr[i][j];
        }
    }

    int maxi;


    cout << maxi << endl;

    // �´� ���
    /*if (equal_arr(arr, height, width))
    {
        answers.push_back(answer);
    }*/


    return 0;
}