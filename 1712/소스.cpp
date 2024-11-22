#include <iostream>
using namespace std;

int main() {
    long long A, B, C; // A: ���� ���, B: ���� ���, C: �Ǹ� ����
    cin >> A >> B >> C;

    // �Ǹ� ������ ���� ��뺸�� ũ�� ������ ���� ���ͺб����� ������ �� ����
    if (B >= C) {
        cout << -1 << endl;
    }
    else {
        // ���ͺб���: A + B * n < C * n -> A / (C - B) < n
        cout << A / (C - B) + 1 << endl;
    }

    return 0;
}
