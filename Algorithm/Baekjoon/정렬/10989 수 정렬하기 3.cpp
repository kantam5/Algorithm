#include <iostream>

using namespace std;

// �ð� ������ ���� scanf, print
// �޸� ������ ���� �Էµ� ���� ī��Ʈ�ؼ� ���� ������ �Էµ� ��ŭ ���
// �ִ� 10000�̹Ƿ� ���̰� 10001�� �迭�� ���� = 4MB < 8MB

int main()
{
    int length;
    scanf_s("%d", &length);

    int arr[10001] = { 0 };

    for (int i = 0; i < length; i++)
    {
        int temp = 0;
        scanf_s("%d", &temp);

        arr[temp]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}