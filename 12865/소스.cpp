#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num, kilo;
    cin >> num >> kilo; // 물건의 개수와 들고갈 수 있는 무게의 최대치를 입력

    vector<int> weights(num + 1, 0); // 각 물건의 무게를 저장하는 배열, 인덱스 1부터 사용
    vector<int> values(num + 1, 0); // 각 물건의 가치를 저장하는 배열, 인덱스 1부터 사용

    // DP 테이블: dp[i][w]는 i번째 물건까지 고려했을 때, 배낭의 용량이 w일 때의 최대 가치를 저장
    vector<vector<int>> dp(num + 1, vector<int>(kilo + 1, 0));

    // 물건의 무게와 가치를 입력받음
    for (int i = 1; i <= num; i++)
    {
        cin >> weights[i] >> values[i]; // i번째 물건의 무게와 가치를 입력받음
    }

    // DP 테이블을 채움
    for (int i = 1; i <= num; i++) // i번째 물건까지 고려
    {
        for (int w = 0; w <= kilo; w++) // 배낭의 현재 무게 한도 w
        {
            if (weights[i] <= w) // 현재 물건을 배낭에 넣을 수 있는 경우
            {
                // i번째 물건을 넣지 않는 경우와 넣는 경우 중 최대 가치를 선택
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i]] + values[i]);
            }
            else
            {
                // i번째 물건을 넣을 수 없는 경우 이전 단계 값 유지
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // 가능한 최대 가치를 출력
    cout << dp[num][kilo] << endl;
    return 0;
}
