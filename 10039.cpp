#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        if (a < 40) a = 40;
        total += a;
    }
    cout << total/5 << endl;
    return 0;
}