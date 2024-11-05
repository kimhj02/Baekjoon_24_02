#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

int main(void)
{
	int total = 0, min_num = 0, su_num = 0;
	int round = 0;
	cin >> total >> min_num >> su_num;

	while (min_num != su_num)
	{
		min_num = (min_num+1) / 2 ;
		su_num = (su_num+1) / 2;
		round++;
	}
	cout << round;
	return 0;
}
