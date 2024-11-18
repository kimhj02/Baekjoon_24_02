#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// �Ҽ� Ȯ�� �Լ�
bool check_decimal(int num)
{
    if (num < 2) return false; // 0�� 1�� �Ҽ��� �ƴ�
    for (int i = 2; i <= sqrt(num); i++) // 2���� ��num���� �˻�
    {
        if (num % i == 0) // ������ �������� �Ҽ��� �ƴ�
            return false;
    }
    return true; // �Ҽ���
}

// �Ӹ���� Ȯ�� �Լ�
bool check_palli(int num)
{
    string s = to_string(num); // ���ڸ� ���ڿ��� ��ȯ
    string reversed_s = string(s.rbegin(), s.rend()); // ���ڿ��� ������
    return s == reversed_s; // ���� ���ڿ��� ������ ���ڿ� ��
}

int main(void)
{
    int low_num = 0; // �ּ� ���� �Է�
    cin >> low_num;

    for (int i = low_num; ; i++) // low_num���� Ž��
    {
        if (check_decimal(i) && check_palli(i)) // �Ҽ��̸鼭 �Ӹ�������� Ȯ��
        {
            cout << i; // ������ �����ϸ� ����ϰ� ����
            break;
        }
    }

    return 0;
}
