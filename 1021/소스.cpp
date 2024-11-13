#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// 왼쪽으로 회전
void rotateLeft(deque<int>& dq) //큐를 입력받아 큐를 왼쪽으로 회전
{
    int front = dq.front(); 
    dq.pop_front();
    dq.push_back(front);
}

// 오른쪽으로 회전
void rotateRight(deque<int>& dq) //큐를 입력받아 큐를 오른쪽으로 회전
{ 
    int back = dq.back();
    dq.pop_back();
    dq.push_front(back);
}

// 특정 값을 가진 요소의 인덱스를 찾음
int findIndex(const deque<int>& dq, int target) 
{
    for (int i = 0; i < dq.size(); i++) 
    {
        if (dq[i] == target) 
        {
            return i;
        }
    }
    return -1; // 만약 target이 없다면 -1 반환 (문제에서는 필요하지 않음)
}

int main() {
    int n, m;
    cin >> n >> m;
    deque<int> dq;
    vector<int> targets(m);

    // 큐에 초기값 삽입
    for (int i = 1; i <= n; i++) 
    {
        dq.push_back(i);
    }

    // 목표로 하는 위치 입력 받기
    for (int i = 0; i < m; i++) 
    {
        cin >> targets[i];
    }

    int total_operations = 0;

    for (int target : targets) 
    {
        int idx = findIndex(dq, target);
        int left_rotations = idx;
        int right_rotations = dq.size() - idx;

        // 최소 회전 수 선택
        if (left_rotations <= right_rotations) 
        {
            // 왼쪽으로 회전
            total_operations += left_rotations;
            while (left_rotations--) 
            {
                rotateLeft(dq);
            }
        }
        else {
            // 오른쪽으로 회전
            total_operations += right_rotations;
            while (right_rotations--) {
                rotateRight(dq);
            }
        }

        // 해당 원소 삭제
        dq.pop_front();
    }
    
    cout << total_operations << endl;
    return 0;
}
