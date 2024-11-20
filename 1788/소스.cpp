#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000000;

int main() {
    int n;
    cin >> n;

    // 피보나치 배열 준비
    int abs_n = abs(n);
    vector<int> fib(abs_n + 1);

    // 초기값 설정
    fib[0] = 0;
    if (abs_n > 0) fib[1] = 1;

    // 양의 피보나치 계산
    for (int i = 2; i <= abs_n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    // 부호 결정
    if (n > 0) {
        cout << 1 << '\n';  // 양수일 때 항상 1
    }
    else if (n < 0) {
        // 음수일 때: (-1)^(n+1) 계산
        if (abs_n % 2 == 0) {
            cout << -1 << '\n'; // 짝수이면 부호는 음수
        }
        else {
            cout << 1 << '\n';  // 홀수이면 부호는 양수
        }
    }
    else {
        cout << 0 << '\n';  // n == 0
    }

    // 절댓값 피보나치 값 출력
    cout << fib[abs_n] << '\n';

    return 0;
}
