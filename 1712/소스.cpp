#include <iostream>
using namespace std;

int main() {
    long long A, B, C; // A: 고정 비용, B: 가변 비용, C: 판매 가격
    cin >> A >> B >> C;

    // 판매 가격이 가변 비용보다 크지 않으면 절대 손익분기점에 도달할 수 없음
    if (B >= C) {
        cout << -1 << endl;
    }
    else {
        // 손익분기점: A + B * n < C * n -> A / (C - B) < n
        cout << A / (C - B) + 1 << endl;
    }

    return 0;
}
