#include <iostream>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    int steps = 0; // 연산 횟수 카운트

    while (B > A) {
        if (B % 10 == 1) {
            // B의 마지막 자리가 1이면 
            B = (B - 1) / 10;
        }
        else if (B % 2 == 0) {
            // B가 짝수라면 2
            B /= 2;
        }
        else {
            // 위 두 조건에 해당하지 않으면 변환 불가
            cout << -1 << endl;
            return 0;
        }
        steps++; // 연산 횟수 증가
    }

    if (B == A) {
        cout << steps + 1 << endl; // 초기 연산 포함
    }
    else {
        // 변환 불가능한 경우
        cout << -1 << endl;
    }

    return 0;
}
