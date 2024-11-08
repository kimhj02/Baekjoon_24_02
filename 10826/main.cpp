#include <iostream>
using namespace std;
#include <vector>

int main(void)
{
	int case_num;
	cin >> case_num;

	vector<long long> dp(case_num+2,0);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i < case_num+2; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2]; // 합을 적용하는 dp로 만듦
	}
	cout << dp[case_num];

	return 0;
}