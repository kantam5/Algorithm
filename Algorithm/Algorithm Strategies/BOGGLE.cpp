#include <iostream>
#include <string>

using namespace std;

const char board[6][6] =
{
    {"URLPM"},
    {"XPRET"},
    {"GIAET"},
    {"XTNZY"},
    {"XOQRS"}
};

const int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool HasWord(int y, int x, const string& word);

bool StartFind(int t, int x, const string& word)
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            if (board[y][x] == word[0])
            {
                if (HasWord(y, x, word))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// ó�� ���� ��ġ���� ���� (0, 0)
// �״��� dy, dx�� �ε����� 1�� ������Ű�鼭 �ش� ��ġ�� ���ڿ��� ������ �ش��ϴ� ���ڰ� �ִ��� Ȯ��
// 
// �������
// 1. y, x�� ������ �ʰ��ϸ� �ȵ� (0 <= y, x <= 4)
// 2. ��ġ (y,x)�� �ִ� ���ڰ� ���ϴ� �ܾ��� ù ���ڰ� �ƴ� ��� �׻� ����
// 3. (1�� ��쿡 �ش���� �ʴ� ���) ���ϴ� �ܾ �� ������ ��� �׻� ����
bool HasWord(int y, int x, const string& word)
{
    if (y < 0 || 4 < y)
    {
        return false;
    }
    if (x < 0 || 4 < x)
    {
        return false;
    }

    if (board[y][x] != word[0])
    {
        return false;
    }

    for (int i = 0; i < 8; ++i)
    {
        HasWord(y + dy[i], x + dx[i], word.substr(1));
        return true;
    }

    return false;
}

//int main()
//{
//    string word = "xoqrs";
//
//    cout << StartFind(0, 0, word) << endl;
//}
