#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int case_num = 0;
    cin >> case_num; // 문자열 개수 입력
    vector<string> arr(case_num);

    for (int i = 0; i < case_num; i++)
    {
        cin >> arr[i]; // 문자열 입력
    }

    string result = arr[0];

    for (int i = 1; i < case_num; i++)
    {
        for (int j = 0; j < result.length(); j++)
        {

            if (result[j] != arr[i][j])
            {
                result[j] = '?';
            }
        }
    }

    cout << result << endl; // 결과 출력

    return 0;
}
