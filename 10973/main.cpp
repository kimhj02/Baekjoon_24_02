#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N; // 배열의 크기 N을 입력받음
    vector<int> arr(N); // 크기가 N인 벡터 생성

    for (int i = 0; i < N; i++) // 배열의 요소를 입력받음
    {
        cin >> arr[i];
    }

    int i = N - 1;
    // 뒤에서부터 순서가 반대인 위치를 찾음
    while (i > 0 && arr[i - 1] <= arr[i])
    {
        i--;
    }

    if (i == 0) // 뒤에서부터 순서를 위반한 위치가 없다면 -1 출력 후 종료
    {
        cout << -1 << endl;
        return 0;
    }

    int j = N - 1;
    // arr[i-1]보다 작은 가장 큰 값을 찾음
    while (arr[j] >= arr[i - 1])
    {
        j--;
    }

    // arr[i-1]과 arr[j]의 위치를 서로 바꿈
    swap(arr[i - 1], arr[j]);

    // i 위치부터 끝까지의 배열을 뒤집어 이전 순열을 만듦
    reverse(arr.begin() + i, arr.end());

    // 결과 출력
    for (int k = 0; k < N; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;

    return 0;
}
