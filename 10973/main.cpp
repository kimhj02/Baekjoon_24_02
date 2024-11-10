#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N; // �迭�� ũ�� N�� �Է¹���
    vector<int> arr(N); // ũ�Ⱑ N�� ���� ����

    for (int i = 0; i < N; i++) // �迭�� ��Ҹ� �Է¹���
    {
        cin >> arr[i];
    }

    int i = N - 1;
    // �ڿ������� ������ �ݴ��� ��ġ�� ã��
    while (i > 0 && arr[i - 1] <= arr[i])
    {
        i--;
    }

    if (i == 0) // �ڿ������� ������ ������ ��ġ�� ���ٸ� -1 ��� �� ����
    {
        cout << -1 << endl;
        return 0;
    }

    int j = N - 1;
    // arr[i-1]���� ���� ���� ū ���� ã��
    while (arr[j] >= arr[i - 1])
    {
        j--;
    }

    // arr[i-1]�� arr[j]�� ��ġ�� ���� �ٲ�
    swap(arr[i - 1], arr[j]);

    // i ��ġ���� �������� �迭�� ������ ���� ������ ����
    reverse(arr.begin() + i, arr.end());

    // ��� ���
    for (int k = 0; k < N; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;

    return 0;
}
