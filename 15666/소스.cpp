#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;  // 입력된 수열을 저장할 벡터
vector<int> result;  // 선택한 결과 조합을 임시로 저장할 벡터

// 깊이 우선 탐색(DFS) 함수
void dfs(int depth, int start)
{
    // 종료 조건: 현재 깊이가 M에 도달하면 조합을 출력
    if (depth == M)
    {
        for (int num : result)
        {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    int a = -1;  // 중복된 숫자 체크를 위한 변수

    for (int i = start; i < N; i++) // 비내림차순 조합을 위해 start부터 시작
    {
        if (arr[i] != a) // 중복된 숫자가 아닌 경우
        {
            result.push_back(arr[i]); // 선택한 숫자를 result 벡터에 추가
            a = arr[i]; // 중복 체크를 위해 선택한 숫자를 a에 저장

            dfs(depth + 1, i); // 다음 깊이로 재귀 호출 (중복 허용, 현재 인덱스 i 포함)

            result.pop_back(); // 백트래킹: 마지막으로 추가된 숫자를 제거
        }
    }
}

int main()
{
    cin >> N >> M; // N: 수열의 길이, M: 선택할 숫자의 개수
    arr.resize(N); // 수열 크기를 N으로 설정

    // 사용자로부터 수열 입력 받기
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // 중복된 조합을 처리하기 위해 수열을 정렬
    sort(arr.begin(), arr.end());

    // 깊이 우선 탐색(DFS) 시작
    dfs(0, 0); // start 값을 0으로 설정하여 첫 번째 숫자부터 탐색
    return 0;
}
