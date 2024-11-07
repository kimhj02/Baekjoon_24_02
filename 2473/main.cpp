#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
    //사용자가 입력한 수만큼 용액을 생성하고 그 용액들중에 3개를 선택해서 특성이 0에 가까운 조합을 찾아서 출력
    int case_num;
    cin >> case_num;
    vector<long long> arr(case_num); // 입력받은 크기만큼 벡터 초기화 3개의 합이 int의 범위를 넘어갈 수 있음으로 long long으로 만듦

    // 용액의 특성 입력
    // + 면 산성 - 면 염기성으로 판단
    for (int i = 0; i < case_num; i++)
    {
        cin >> arr[i];
    }

    // 입력받은 용액들을 정렬
    sort(arr.begin(), arr.end());

    long long closest_sum = 9223372036854775807; //long long 최대값
    //최적의 용액 3개를 저장하기 위한 값 인덱스로 표현
    int result1 = 0, result2 = 1, result3 = 2; 

    for (int i = 0; i < case_num - 2; i++)
    {
        int left = i + 1;
        int right = case_num - 1;

        while (left < right) 
        {
            long long sum = arr[i] + arr[left] + arr[right];

            if (abs(sum) < abs(closest_sum)) //절재값으로 계산
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
