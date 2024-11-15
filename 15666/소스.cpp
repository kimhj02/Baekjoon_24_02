#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;  // �Էµ� ������ ������ ����
vector<int> result;  // ������ ��� ������ �ӽ÷� ������ ����

// ���� �켱 Ž��(DFS) �Լ�
void dfs(int depth, int start)
{
    // ���� ����: ���� ���̰� M�� �����ϸ� ������ ���
    if (depth == M)
    {
        for (int num : result)
        {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    int a = -1;  // �ߺ��� ���� üũ�� ���� ����

    for (int i = start; i < N; i++) // �񳻸����� ������ ���� start���� ����
    {
        if (arr[i] != a) // �ߺ��� ���ڰ� �ƴ� ���
        {
            result.push_back(arr[i]); // ������ ���ڸ� result ���Ϳ� �߰�
            a = arr[i]; // �ߺ� üũ�� ���� ������ ���ڸ� a�� ����

            dfs(depth + 1, i); // ���� ���̷� ��� ȣ�� (�ߺ� ���, ���� �ε��� i ����)

            result.pop_back(); // ��Ʈ��ŷ: ���������� �߰��� ���ڸ� ����
        }
    }
}

int main()
{
    cin >> N >> M; // N: ������ ����, M: ������ ������ ����
    arr.resize(N); // ���� ũ�⸦ N���� ����

    // ����ڷκ��� ���� �Է� �ޱ�
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // �ߺ��� ������ ó���ϱ� ���� ������ ����
    sort(arr.begin(), arr.end());

    // ���� �켱 Ž��(DFS) ����
    dfs(0, 0); // start ���� 0���� �����Ͽ� ù ��° ���ں��� Ž��
    return 0;
}
