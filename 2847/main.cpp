#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int case_num = 0;
	int count = 0;

	cin >> case_num;
	vector <int> arr(case_num,0); //�Է¹��� ũ�⸸ŭ ���� 0���� �ʱ�ȭ

	for (int i = 0; i < case_num; i++) //�Է� �ޱ�
	{
		cin >> arr[i];
	}

	int pre = arr[case_num - 1]; //�������� �ִ� ��

	for (int i = case_num - 2; i >= 0; i--)
	{
		while (true)
		{
			if (arr[i] >= pre)
			{
				arr[i]--;
				count++;
			}
			else
			{
				break;
			}
		}
		pre = arr[i];
	}
	cout << count;
	return 0;
}