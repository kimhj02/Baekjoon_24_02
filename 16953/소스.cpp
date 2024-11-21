#include <iostream>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    int steps = 0; // ���� Ƚ�� ī��Ʈ

    while (B > A) {
        if (B % 10 == 1) {
            // B�� ������ �ڸ��� 1�̸� 
            B = (B - 1) / 10;
        }
        else if (B % 2 == 0) {
            // B�� ¦����� 2
            B /= 2;
        }
        else {
            // �� �� ���ǿ� �ش����� ������ ��ȯ �Ұ�
            cout << -1 << endl;
            return 0;
        }
        steps++; // ���� Ƚ�� ����
    }

    if (B == A) {
        cout << steps + 1 << endl; // �ʱ� ���� ����
    }
    else {
        // ��ȯ �Ұ����� ���
        cout << -1 << endl;
    }

    return 0;
}
