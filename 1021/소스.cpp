#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// �������� ȸ��
void rotateLeft(deque<int>& dq) //ť�� �Է¹޾� ť�� �������� ȸ��
{
    int front = dq.front(); 
    dq.pop_front();
    dq.push_back(front);
}

// ���������� ȸ��
void rotateRight(deque<int>& dq) //ť�� �Է¹޾� ť�� ���������� ȸ��
{ 
    int back = dq.back();
    dq.pop_back();
    dq.push_front(back);
}

// Ư�� ���� ���� ����� �ε����� ã��
int findIndex(const deque<int>& dq, int target) 
{
    for (int i = 0; i < dq.size(); i++) 
    {
        if (dq[i] == target) 
        {
            return i;
        }
    }
    return -1; // ���� target�� ���ٸ� -1 ��ȯ (���������� �ʿ����� ����)
}

int main() {
    int n, m;
    cin >> n >> m;
    deque<int> dq;
    vector<int> targets(m);

    // ť�� �ʱⰪ ����
    for (int i = 1; i <= n; i++) 
    {
        dq.push_back(i);
    }

    // ��ǥ�� �ϴ� ��ġ �Է� �ޱ�
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

        // �ּ� ȸ�� �� ����
        if (left_rotations <= right_rotations) 
        {
            // �������� ȸ��
            total_operations += left_rotations;
            while (left_rotations--) 
            {
                rotateLeft(dq);
            }
        }
        else {
            // ���������� ȸ��
            total_operations += right_rotations;
            while (right_rotations--) {
                rotateRight(dq);
            }
        }

        // �ش� ���� ����
        dq.pop_front();
    }
    
    cout << total_operations << endl;
    return 0;
}
