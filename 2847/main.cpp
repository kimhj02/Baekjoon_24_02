#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int case_num = 0;
	int count = 0;

	cin >> case_num;
	vector <int> arr(case_num,0); //입력받은 크기만큼 벡터 0으로 초기화

	for (int i = 0; i < case_num; i++) //입력 받기
	{
		cin >> arr[i];
	}

	int pre = arr[case_num - 1]; //마지막에 있는 수

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