#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int case_num = 0;
    cin >> case_num; // ���ڿ� ���� �Է�
    vector<string> arr(case_num);

    for (int i = 0; i < case_num; i++)
    {
        cin >> arr[i]; // ���ڿ� �Է�
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

    cout << result << endl; // ��� ���

    return 0;
}
