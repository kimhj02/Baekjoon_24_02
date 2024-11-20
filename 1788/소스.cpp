#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000000;

int main() {
    int n;
    cin >> n;

    // �Ǻ���ġ �迭 �غ�
    int abs_n = abs(n);
    vector<int> fib(abs_n + 1);

    // �ʱⰪ ����
    fib[0] = 0;
    if (abs_n > 0) fib[1] = 1;

    // ���� �Ǻ���ġ ���
    for (int i = 2; i <= abs_n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    // ��ȣ ����
    if (n > 0) {
        cout << 1 << '\n';  // ����� �� �׻� 1
    }
    else if (n < 0) {
        // ������ ��: (-1)^(n+1) ���
        if (abs_n % 2 == 0) {
            cout << -1 << '\n'; // ¦���̸� ��ȣ�� ����
        }
        else {
            cout << 1 << '\n';  // Ȧ���̸� ��ȣ�� ���
        }
    }
    else {
        cout << 0 << '\n';  // n == 0
    }

    // ���� �Ǻ���ġ �� ���
    cout << fib[abs_n] << '\n';

    return 0;
}
