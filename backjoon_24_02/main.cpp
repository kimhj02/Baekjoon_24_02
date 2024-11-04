#include <iostream>
#include <vector>
using namespace std;

// DFS �Լ� ����
void dfs(vector<vector<int>>& map, int x, int y, int row, int column) 
{
    // ���� ���� (��, ��, ��, ��)
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    // ���� ��ġ �湮 ó��
    map[x][y] = 0;

    // ������ 4���� Ž��
    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // ���� ��ǥ�� ��ȿ ���� ���� �ְ� ���߰� �ִ� ���
        if (nx >= 0 && nx < row && ny >= 0 && ny < column && map[nx][ny] == 1) 
        {
            dfs(map, nx, ny, row, column);
        }
    }
}

int main(void) 
{
    int test_case, row, column, num;
    int x, y;
    cin >> test_case; // test_case �Է�

    for (int i = 0; i < test_case; i++) 
    {
        cin >> row >> column >> num; // ����, ����, ���� �Է� �ޱ�

        vector<vector<int>> map(row, vector<int>(column, 0)); // 0���� �ʱ�ȭ�� 2D ����

        for (int j = 0; j < num; j++) { // ����ڰ� �Է��� ��ġ�� �� 1�� ����
            cin >> x >> y;
            if (x >= 0 && x < row && y >= 0 && y < column) { // ���� �ε��� ���� �˻�
                map[x][y] = 1;
            }
        }

        int bug_count = 0; // ���� �� �ʱ�ȭ

        // ��� ��ġ Ž���Ͽ� ����� ������Ʈ �� ���ϱ�
        for (int r = 0; r < row; r++) 
        {
            for (int c = 0; c < column; c++) 
            {
                if (map[r][c] == 1) { // ���߰� �ִ� ���
                    dfs(map, r, c, row, column); // DFS ȣ��
                    bug_count++; // ���� �� ����
                }
            }
        }

        cout << bug_count << endl; // ��� ���
    }

    return 0;
}
