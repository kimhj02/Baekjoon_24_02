#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num, kilo;
    cin >> num >> kilo; // ������ ������ ��� �� �ִ� ������ �ִ�ġ�� �Է�

    vector<int> weights(num + 1, 0); // �� ������ ���Ը� �����ϴ� �迭, �ε��� 1���� ���
    vector<int> values(num + 1, 0); // �� ������ ��ġ�� �����ϴ� �迭, �ε��� 1���� ���

    // DP ���̺�: dp[i][w]�� i��° ���Ǳ��� ������� ��, �賶�� �뷮�� w�� ���� �ִ� ��ġ�� ����
    vector<vector<int>> dp(num + 1, vector<int>(kilo + 1, 0));

    // ������ ���Կ� ��ġ�� �Է¹���
    for (int i = 1; i <= num; i++)
    {
        cin >> weights[i] >> values[i]; // i��° ������ ���Կ� ��ġ�� �Է¹���
    }

    // DP ���̺��� ä��
    for (int i = 1; i <= num; i++) // i��° ���Ǳ��� ���
    {
        for (int w = 0; w <= kilo; w++) // �賶�� ���� ���� �ѵ� w
        {
            if (weights[i] <= w) // ���� ������ �賶�� ���� �� �ִ� ���
            {
                // i��° ������ ���� �ʴ� ���� �ִ� ��� �� �ִ� ��ġ�� ����
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i]] + values[i]);
            }
            else
            {
                // i��° ������ ���� �� ���� ��� ���� �ܰ� �� ����
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // ������ �ִ� ��ġ�� ���
    cout << dp[num][kilo] << endl;
    return 0;
}
