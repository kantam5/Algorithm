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

// 처음 들어온 위치에서 시작 (0, 0)
// 그다음 dy, dx의 인덱스를 1씩 증가시키면서 해당 위치에 문자열의 다음에 해당하는 문자가 있는지 확인
// 
// 기저사례
// 1. y, x가 범위를 초과하면 안됨 (0 <= y, x <= 4)
// 2. 위치 (y,x)에 있는 글자가 원하는 단어의 첫 글자가 아닌 경우 항상 실패
// 3. (1번 경우에 해당되지 않는 경우) 원하는 단어가 한 글자인 경우 항상 성공
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
