#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int test_case = 0;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        int n, m; // n: ������ ��, m: ������� ��

        cin >> n >> m;

        for (int j = 0; j < m; j++) 
        {
            int a, b;
            cin >> a >> b;
        }

        cout << n - 1 << endl;
    }

    return 0;
}