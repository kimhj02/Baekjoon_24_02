#include <iostream>
using namespace std;
#include <vector>

int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> arr(n,0); //1차원 벡터 0으로 초기화
	int count = 0;
	int total = 0;

	for (int i = 0; i < n; i++) //vector 배열 입력
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			total += arr[j];
			if (total == m)
			{
				count++;
				break;
			}
			else if (total > m)
			{
				break;
			}
		}
		total = 0;
	}
	cout << count;
	return 0;
}