#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// 소수 확인 함수
bool check_decimal(int num)
{
    if (num < 2) return false; // 0과 1은 소수가 아님
    for (int i = 2; i <= sqrt(num); i++) // 2부터 √num까지 검사
    {
        if (num % i == 0) // 나누어 떨어지면 소수가 아님
            return false;
    }
    return true; // 소수임
}

// 팰린드롬 확인 함수
bool check_palli(int num)
{
    string s = to_string(num); // 숫자를 문자열로 변환
    string reversed_s = string(s.rbegin(), s.rend()); // 문자열을 뒤집음
    return s == reversed_s; // 원래 문자열과 뒤집은 문자열 비교
}

int main(void)
{
    int low_num = 0; // 최소 숫자 입력
    cin >> low_num;

    for (int i = low_num; ; i++) // low_num부터 탐색
    {
        if (check_decimal(i) && check_palli(i)) // 소수이면서 팰린드롬인지 확인
        {
            cout << i; // 조건을 만족하면 출력하고 종료
            break;
        }
    }

    return 0;
}
