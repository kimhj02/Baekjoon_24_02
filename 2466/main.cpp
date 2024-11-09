#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findRelationship(int start, int end, const vector<vector<int>>& relations, int n) {
    vector<int> visited(n + 1, -1); // �湮 ���� �� �̼� ��� (-1: �̹湮)
    queue<int> q;

    q.push(start);
    visited[start] = 0; // ���� ���� �̼� 0

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : relations[current]) {
            if (visited[next] == -1) { // �湮���� ���� �����
                visited[next] = visited[current] + 1;
                q.push(next);

                if (next == end) { // ���� ������ �������� ��
                    return visited[next];
                }
            }
        }
    }

    return -1; // ������� �ʾ��� ��
}

int main() {
    int n, a, b, m;
    cin >> n >> a >> b >> m;

    vector<vector<int>> relations(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        relations[x].push_back(y);
        relations[y].push_back(x);
    }

    int result = findRelationship(a, b, relations, n);
    cout << result << endl;

    return 0;
}
