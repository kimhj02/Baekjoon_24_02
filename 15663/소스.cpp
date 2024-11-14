#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;  // 입력된 수열을 저장할 벡터
vector<int> result;  // 선택한 결과 조합을 임시로 저장할 벡터
vector<bool> visited;  // 각 요소 방문 여부를 확인하는 벡터

// 깊이 우선 탐색(DFS) 함수
void dfs(int depth)
{
    // 종료 조건: 현재 깊이가 M에 도달하면 조합을 출력
    if (depth == M) // M개의 숫자를 선택한 경우
    {
        for (int num : result) // result 벡터에 있는 숫자들을 출력
        {
            cout << num << " "; // 숫자 출력
        }
        cout << "\n"; // 한 조합이 끝났으므로 줄바꿈
        return; // 더 깊이 탐색하지 않고 종료
    }

    int a = -1;  // 중복된 숫자 체크를 위한 변수 (이전에 사용한 숫자를 저장)

    for (int i = 0; i < N; i++) // 전체 숫자들을 순회
    {
        // 해당 숫자가 방문되지 않았고, 중복된 숫자가 아닌 경우에만 선택
        if (!visited[i] && arr[i] != a) // arr[i]가 현재 조합에 포함되지 않았고 중복되지 않은 경우
        {
            visited[i] = true; // 현재 위치를 방문 표시
            result.push_back(arr[i]); // 선택한 숫자를 result 벡터에 추가
            a = arr[i]; // 중복 체크를 위해 선택한 숫자를 a에 저장

            dfs(depth + 1); // 다음 깊이로 재귀 호출, 숫자를 하나 더 선택하기 위해 depth 증가

            // 백트래킹: 마지막에 추가한 숫자와 방문 기록을 제거
            result.pop_back(); // 마지막으로 추가된 숫자를 제거하여 다음 경우의 수를 탐색
            visited[i] = false; // 방문 여부 초기화
        }
    }
}

int main()
{
    cin >> N >> M; // N: 수열의 길이, M: 선택할 숫자의 개수
    arr.resize(N); // 수열 크기를 N으로 설정
    visited.resize(N, false); // 방문 여부를 N개 모두 false로 초기화

    // 사용자로부터 수열 입력 받기
    for (int i = 0; i < N; i++) // N개의 수열 값을 입력
    {
        cin >> arr[i];
    }

    // 중복된 조합을 피하기 위해 수열을 정렬 (같은 숫자끼리 모아 중복을 쉽게 처리)
    sort(arr.begin(), arr.end());

    // 깊이 우선 탐색(DFS) 시작
    dfs(0); // 0부터 시작하여 depth를 증가시키며 M개 선택
    return 0;
}
