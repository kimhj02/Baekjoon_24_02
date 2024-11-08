#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct work
{
    int day;
    int money;
} Work;

int main(void)
{
    int case_num;
    cin >> case_num;

    vector<Work> works(case_num + 1);
    vector<int> dp(case_num + 1, 0);

    for (int i = 1; i <= case_num; i++)
    {
        cin >> works[i].day >> works[i].money;
    }

    for (int i = 1; i <= case_num; i++)
    {
        dp[i] = max(dp[i], dp[i - 1]);

        int next_day = i + works[i].day;
        if (next_day <= case_num + 1) 
        {
            dp[next_day - 1] = max(dp[next_day - 1], dp[i - 1] + works[i].money);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
