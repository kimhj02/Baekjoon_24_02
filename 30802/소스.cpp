#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N, S, M, L, XL, XXL, XXXL;
    long long T, P;
    cin >> N;
    cin >> S >> M >> L >> XL >> XXL >> XXXL;
    cin >> T >> P;

    // Æ¼¼ÅÃ÷ ¹­À½ °è»ê
    long long total_shirts = 0;
    total_shirts += (S + T - 1) / T;
    total_shirts += (M + T - 1) / T;
    total_shirts += (L + T - 1) / T;
    total_shirts += (XL + T - 1) / T;
    total_shirts += (XXL + T - 1) / T;
    total_shirts += (XXXL + T - 1) / T;

    // Ææ ¹­À½ °è»ê
    long long pen_bundles = N / P;
    long long remaining_pens = N % P;

    // °á°ú Ãâ·Â
    cout << total_shirts << endl;
    cout << pen_bundles << " " << remaining_pens << endl;

    return 0;
}
