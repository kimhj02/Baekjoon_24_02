#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
    //����ڰ� �Է��� ����ŭ ����� �����ϰ� �� ��׵��߿� 3���� �����ؼ� Ư���� 0�� ����� ������ ã�Ƽ� ���
    int case_num;
    cin >> case_num;
    vector<long long> arr(case_num); // �Է¹��� ũ�⸸ŭ ���� �ʱ�ȭ 3���� ���� int�� ������ �Ѿ �� �������� long long���� ����

    // ����� Ư�� �Է�
    // + �� �꼺 - �� ���⼺���� �Ǵ�
    for (int i = 0; i < case_num; i++)
    {
        cin >> arr[i];
    }

    // �Է¹��� ��׵��� ����
    sort(arr.begin(), arr.end());

    long long closest_sum = 9223372036854775807; //long long �ִ밪
    //������ ��� 3���� �����ϱ� ���� �� �ε����� ǥ��
    int result1 = 0, result2 = 1, result3 = 2; 

    for (int i = 0; i < case_num - 2; i++)
    {
        int left = i + 1;
        int right = case_num - 1;

        while (left < right) 
        {
            long long sum = arr[i] + arr[left] + arr[right];

            if (abs(sum) < abs(closest_sum)) //���簪���� ���
            {
                closest_sum = sum;
                result1 = i;
                result2 = left;
                result3 = right;
            }

            if (sum < 0) 
            {
                left++;
            }
            else 
            {
                right--;
            }
        }
    }

    cout << arr[result1] << " " << arr[result2] << " " << arr[result3];
    return 0;
}
